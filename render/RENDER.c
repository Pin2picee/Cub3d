/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:13:24 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/27 18:15:45 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

/**
 * il me faudrais une fonction qui put le pixel 
*/
void    put_pixel(int x, int y, int color, t_game *data)
{
    int index;
    
    if (x > RESOLUTION_L || x < 0 || y > RESOLUTION_H || y < 0)
        return ;
    index = y * data->frame.size_line + x * data->frame.bpp / 8; //index du bon groupement de pixel a avoir
    
    data->frame.data[index] = color & 0xFF;// on extrait la couleur bleu, BVR car stocker en little endian comme dans la memoire
    data->frame.data[index + 1] = (color >> 8) & 0xFF;
    data->frame.data[index + 2] = (color >> 16) & 0xFF;
}

/*
===================================
        Projete un rayon 
        puis dessine le mur de haut en bas
===================================
*/
void    project_rayon(t_game *d, double start_angle, int i)
{   
    int     texture_x;
    int     texture_y;
    int     color;
    double  ratio;
    
    d->r_x = d->pos_player.x;
    d->r_y = d->pos_player.y;
    while (d->map[(int)d->r_y][(int)d->r_x] != '1')
    {
        d->r_x += cos(start_angle) * 0.01;
        d->r_y += sin(start_angle) * 0.01;
    }
    what_texture(d, start_angle);// determine quelle texture afficher par pixel -> rayon
    info_recast(d, start_angle);// fait les calcul pour la taille des murs en fonction de la distance
    texture_x = ft_do_x(d);
    ratio = (double)d->tab_img[d->choice]->height / (double)d->wall_size;
    while (++d->start_y < d->finish)
    {
        texture_y = (int)((d->start_y - (RESOLUTION_H - d->wall_size) / 2.0) * ratio) % d->tab_img[d->choice]->height;
        if (texture_y < 0) 
            texture_y += d->tab_img[d->choice]->height;
        color = *(int *)(d->tab_img[d->choice]->data + (texture_y * d->tab_img[d->choice]->width + texture_x) * 4);
        put_pixel(i, d->start_y, color, d);
    }
}

/*
======================================================================
        Fonction qui determine envoie de gauche 
        a droite tout les rayon dans un fov
        de 60 degers
======================================================================
*/
void    fov(t_game *data)
{
    double rayon_start;
    double  increment_rayon;
    int     i;

    i = 0;
    rayon_start = (data->player_angle - (PI / 6));// tout a droite
    increment_rayon = (PI / 3 / RESOLUTION_L);// jusqu'a tout a gauche
    while (i < RESOLUTION_L && rayon_start < data->player_angle + PI / 6)
    {
        rayon_start += increment_rayon;//   PI / 3 -> 60 degres divise par la largeur de ma fenetre
        project_rayon(data, rayon_start, i);
        i++;
    }
}

/*
===================================
            Type fps loop
===================================
*/
int loop_game(t_game *data)
{
    //data->fps++;
    move_player(data);
    clean_img(data);
    //mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, 0, 0);
    floor_and_ceiling(data);//fonction qui affiche sol et plafond
    fov(data);
    draw_square(data->pos_player.x * 10, data->pos_player.y * 10, 5, rouge, data);// perso
    map_render(data);// minimap
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, 0, 0);
    return (0);
}

/*
===================================
        POINT DE DEPART
===================================
*/
int init_my_mlx(t_game *data)
{
    //data->fps = 0;
    data->mlx_ptr = mlx_init();// demarre la mlx
    if (!data->mlx_ptr)
        return (1);
    load_texture(data);
    data->mlx_window = mlx_new_window(data->mlx_ptr, RESOLUTION_L, RESOLUTION_H, NAME_WINDOW);// on ouvre un window
    if (!data->mlx_window)
        return (free(data->mlx_ptr), 1);
    data->frame.img = mlx_new_image(data->mlx_ptr, RESOLUTION_L, RESOLUTION_H);// on creer une pointeur d'image
    if (!data->frame.img)
        return (free(data->mlx_ptr), 1);
    data->frame.data = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.size_line, &data->frame.endian);// on recupere les info de cette image et stock l'image dans une chaine de caracteres
    init_hook(data);
    mlx_hook(data->mlx_window, 2, 1L<<0, key_press, data);// pour les touches
    mlx_hook(data->mlx_window, 3, 1L<<1, key_reset, data);// pour reset les touchesune fois lacher
    // pour rendre le jeux plus fluide en terme d'fps il faut une generation d'image en boucle c'est pourc ela qu'on utilise mlx_loop_hook
    mlx_loop_hook(data->mlx_ptr, loop_game, data);
    return (0);
}



//TODO:
/*

    ->Aller recup la bonne texture avec la bonne chop_texture
    -> afficher la bonne couleur des cles C et F
*/