/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER_FINAL.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:09:45 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/26 18:46:39 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"


#define EPSILON 0.01

int ft_check_verti(double x, double y)
{
    (void)y;
    if (fabs(x - round(x)) <= EPSILON)  // Comparaison avec epsilon
        return 42;
    return 0;
}

int ft_check_horizon(double x, double y)
{
    (void)x;
    if (fabs(y - round(y)) <= EPSILON)  // Comparaison avec epsilon
        return 42;
    return 0;
}


double  get_distance_rayon(double x_1, double x_2, double y_1, double y_2)
{
    double distance_rayon;
    
    distance_rayon = pow(Vabsolue(x_1 - x_2), 2) + pow(Vabsolue(y_1 - y_2), 2); //theoreme de pythagore
    distance_rayon = sqrt(distance_rayon);
    return (distance_rayon);
}

void what_texture(t_game *d, double start_angle)
{
    int verti;
    int horizon;

    verti = ft_check_verti(d->r_x, d->r_y);
    horizon = ft_check_horizon(d->r_x, d->r_y);
    if (verti == 42 && horizon != 42)
    {
        if (cos(start_angle) < 0)
            d->choice = 0;
        else if (cos(start_angle > 0))
            d->choice = 1;
    }
    else if (horizon == 42 && verti != 42)
    {
        if (sin(start_angle) > 0)
            d->choice = 2;
        else if (sin(start_angle) < 0)
            d->choice = 3;
    }
}

void    info_recast(t_game *d, double start_angle)
{
    d->dist_rayon = get_distance_rayon(d->r_x, d->pos_player.x, d->r_y, d->pos_player.y);
    d->wall_size = ( 90 / d->dist_rayon) * (d->map_height / 2) / cos(d->player_angle - start_angle);
    d->start_y = (RESOLUTION_H - d->wall_size) / 2 - 1; // le -1 pour gagner une ligne dans la boucle de projection de rayon en y
    d->finish = d->start_y + d->wall_size;
}

int ft_do_x(t_game *d)
{
    int tmp;
    if (d->choice == 0 || d->choice == 1)
    tmp = (int)(d->r_y * d->tab_img[d->choice]->width) % d->tab_img[d->choice]->width;
    else
        tmp = (int)(d->r_x * d->tab_img[d->choice]->width) % d->tab_img[d->choice]->width;
    return (tmp);
}