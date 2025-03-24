/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:13:24 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/24 18:35:59 by abelmoha         ###   ########.fr       */
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

void    init_game(t_game *data)
{
    init_hook(data);// on les init a false
   //draw_square(data->pos_player.x * 64, data->pos_player.y * 64, 5, rouge,  data);// on dessine un carrer qui represente le personnage
}

void    project_rayon_precis(t_game *data, double start_angle, double *rayon_x, double *rayon_y)
{
    int  px;
    int  py;
    
    while (data->map[(int)*rayon_y][(int)*rayon_x] != '1')
    {
        px = (int)(*rayon_x * 10);
        py = (int)(*rayon_y * 10);
        put_pixel(px, py, 0xFFFF00, data);
        
        *rayon_x += cos(start_angle) * 0.01;
        *rayon_y += sin(start_angle) * 0.01;
    }
    // calculer la distance du rayon puis afficher un mur en fonction de cela
}

void    project_rayon(t_game *data, double start_angle, int i)
{
    double  rayon_x;
    double  rayon_y;
    int  px;
    int  py;
    double distance_rayon;
    
    rayon_x = data->pos_player.x;
    rayon_y = data->pos_player.y;
    while (data->map[(int)rayon_y][(int)rayon_x] != '1')
    {
        px = (int)(rayon_x * 10);
        py = (int)(rayon_y * 10);
        put_pixel(px, py, 0xFFFF00, data);
        
        rayon_x += cos(start_angle) * 0.5;
        rayon_y += sin(start_angle) * 0.5;
    }
    rayon_x -= cos(start_angle) * 0.5;
    rayon_y -= sin(start_angle) * 0.5;
    project_rayon_precis(data, start_angle, &rayon_x, &rayon_y);// opti
    distance_rayon = pow(Vabsolue(rayon_x - data->pos_player.x), 2) + pow(Vabsolue(rayon_y - data->pos_player.y), 2); //theoreme de pythagore
    distance_rayon = sqrt(distance_rayon);
    put_pixel(i, RESOLUTION_H / 2, bleu, data);
    
    // calculer la distance du rayon puis afficher un mur en fonction de cela
}

void    fov(t_game *data)
{
    double rayon_start;
    double  increment_rayon;
    int     i;

    i = 0;
    rayon_start = (data->player_angle - (PI / 6));
    increment_rayon = (PI / 3 / RESOLUTION_L);
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
    draw_square(data->pos_player.x * 10, data->pos_player.y * 10, 5, rouge, data);
    
    
    fov(data);
    map_render(data);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, 0, 0);
    return (0);
}

int init_my_mlx(t_game *data)
{
    data->mlx_ptr = mlx_init();// demarre la mlx
    if (!data->mlx_ptr)
        return (1);
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
