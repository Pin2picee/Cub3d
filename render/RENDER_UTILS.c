/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER_UTILS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:23:42 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/24 18:02:53 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void draw_wall(int x, int y, int size, int color, t_game *data)
{
    int i = 0;
    while (i < size)
        put_pixel(x + i++, y , color, data);// haut
    i = 0;
    while (i < size)
        put_pixel(x, y + i++, color, data);// gauche
    i = 0;
    while (i < size)
        put_pixel(x + i++, y + size, color, data);//bas
    i = 0;
    while (i < size)
        put_pixel(x + size, y + i++, color, data);// droite
}

void draw_square(int x, int y, int size, int color, t_game *data)
{
    int i = 0;
    while (i < size)
        put_pixel(x + i++ - size / 2, y - size / 2 , color, data);
    i = 0;
    while (i < size)
        put_pixel(x - size / 2, y + i++ - size / 2, color, data);
    i = 0;
    while (i < size)
        put_pixel(x + i++ - size / 2, y + size / 2, color, data);
    i = 0;
    while (i < size)
        put_pixel(x + size / 2, y + i++ - size / 2, color, data);
}

void    clean_img(t_game *data)
{
    int x;
    int y;
    

    x = 0;
    y = 0;
    while (y < RESOLUTION_H)
    {
        x = 0;
        while (x < RESOLUTION_L)
        {
            put_pixel(x, y, 0, data);
            x++;
        }
        y++;
    }
}

void map_render(t_game *data)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
                draw_wall(x * 10, y * 10, 10, bleu, data);
            x++;
        }
        y++;
    }
}

double  Vabsolue(double nb)
{
    if (nb < 0)
        return (-nb);
    return (nb);
}