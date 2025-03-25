/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:13:24 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/25 18:43:49 by abelmoha         ###   ########.fr       */
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

void    put_pixel_2(int x, int y, int color, t_game *data)
{
    int index;
    
    if (x > RESOLUTION_L || x < 0 || y > RESOLUTION_H || y < 0)
        return ;
    index = y * data->frame.size_line + x * data->frame.bpp / 8; //index du bon groupement de pixel a avoir
    
    data->frame.data[index] = color & 0xFF;// on extrait la couleur bleu, BVR car stocker en little endian comme dans la memoire
    data->frame.data[index + 1] = (color >> 8) & 0xFF;
    data->frame.data[index + 2] = (color >> 16) & 0xFF;
}

void    init_game(t_game *data)
{
    init_hook(data);// on les init a false
   //draw_square(data->pos_player.x * 64, data->pos_player.y * 64, 5, rouge,  data);// on dessine un carrer qui represente le personnage
}

void    project_rayon_precis(t_game *data, double start_angle, double *rayon_x, double *rayon_y)
{
    //int  px;
    //int  py;
    
    while (data->map[(int)*rayon_y][(int)*rayon_x] != '1')
    {
        //px = (int)(*rayon_x * 10);
        //py = (int)(*rayon_y * 10);
        //put_pixel(px, py, 0xFFFF00, data);
        
        *rayon_x += cos(start_angle) * 0.01;
        *rayon_y += sin(start_angle) * 0.01;
    }
    // calculer la distance du rayon puis afficher un mur en fonction de cela
}

void    project_rayon(t_game *data, double start_angle, int i)
{
    double  rayon_x;
    double  rayon_y;
    //int  px;
    //int  py;
    double distance_rayon;
    double taille_mur;
    int finish;
    int start_y;
    
    rayon_x = data->pos_player.x;
    rayon_y = data->pos_player.y;
    while (data->map[(int)rayon_y][(int)rayon_x] != '1')
    {
        //px = (int)(rayon_x * 10);
        //py = (int)(rayon_y * 10);
        //put_pixel(px, py, 0xFFFF00, data);
        
        rayon_x += cos(start_angle) * 0.01;
        rayon_y += sin(start_angle) * 0.01;
    }
    rayon_x -= cos(start_angle) * 0.01;
    rayon_y -= sin(start_angle) * 0.01;
    project_rayon_precis(data, start_angle, &rayon_x, &rayon_y);// opti
    distance_rayon = pow(Vabsolue(rayon_x - data->pos_player.x), 2) + pow(Vabsolue(rayon_y - data->pos_player.y), 2); //theoreme de pythagore
    distance_rayon = sqrt(distance_rayon);// racine carre de delta x sur delta y
    
    taille_mur = ( 130 / distance_rayon) * (data->map_height / 2) / cos(data->player_angle - start_angle);
    //printf ("%d\n", taille_mur);
    start_y = (RESOLUTION_H - taille_mur) / 2;
    finish = start_y + taille_mur;
    //int texture_x = (int)(rayon_x * data->SO_t.width) % data->SO_t.width;
    //int texture_y;
    //int color;

    while (start_y < finish)
    {
        // Coordonnée y de la texture
        //texture_y = (int)((start_y - (RESOLUTION_H - taille_mur) / 2) * data->SO_t.height / taille_mur) % data->SO_t.height;
       // color = *(int *)(data->SO_t.data + (texture_y * data->SO_t.width + texture_x) * 4);
        put_pixel(i, start_y, 0xFF0000, data);
        start_y++;
    }
    
}

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

int loop_game(t_game *data)
{    
    move_player(data);
    clean_img(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, 0, 0);
    floor_and_ceiling(data);//fonction qui affiche sol et plafond
    fov(data);
    draw_square(data->pos_player.x * 10, data->pos_player.y * 10, 5, rouge, data);// perso
    map_render(data);// minimap
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, 0, 0);
    return (0);
}

int init_my_mlx(t_game *data)
{
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
    init_game(data);
    
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