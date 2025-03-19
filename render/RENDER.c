/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:13:24 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/19 16:16:33 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"
//mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, x * data->frame.bpp / 8, y * data->frame.size_line);

void    put_pixel(t_game *data, int x, int y, int color)
{
    int index;

    index = (y * data->frame.size_line) + (x * data->frame.bpp / 8);
    data->frame.data[index] = color & 0xFF;               // Bleu
    data->frame.data[index + 1] = (color >> 8) & 0xFF;     // Vert
    data->frame.data[index + 2] = (color >> 16) & 0xFF; 
}

void    draw_bloc(int x, int y, int size, t_game *data)
{
    int i;

    i = 0;
    while (i < size)
    {
        put_pixel(data, x + i, y, verte);
        put_pixel(data, x, y + i, verte);
        put_pixel(data, x + i, y + size, verte);
        put_pixel(data, x + size, y + i, verte);
        i++;      
    }

}

void    clear_image(int x, int y, t_game *data)
{
    int i;
    int j;

    i = 0;
    while (i < RESOLUTION_H)
    {
        j = 0;
        while (j < RESOLUTION_L)
        {
            put_pixel(data, x + j, y + i, 0);
            j++;
        }
        i++;      
    }
}

void    draw_sol(int x, int y, int size, t_game *data)
{
    int i;

    i = 0;
    while (i < size)
    {
        put_pixel(data, x + i, y, rouge);
        put_pixel(data, x, y + i, rouge);
        put_pixel(data, x + i, y + size, rouge);
        put_pixel(data, x + size, y + i, rouge);
        i++;      
    }

}

void draw_personnage(int x, int y, int size, t_game *data)
{
    int i;

    i = 0;
    while (i < size)
    {
        put_pixel(data, x + i, y, bleu);
        put_pixel(data, x, y + i, bleu);
        put_pixel(data, x + i, y + size, bleu);
        put_pixel(data, x + size, y + i, bleu);
        i++;      
    }
}

void    ft_render(t_game *data, int x, int y)
{
    clear_image(0, 0, data);
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == '1')
                draw_bloc(x * 64, y * 64, 64, data);
                
            x++;
        }
        y++;
    }
   draw_personnage((int)data->pos_player.x * 64, (int)data->pos_player.y * 64, 64, data);
}

int hook_key(int keypress, t_game *data)
{
    (void)data;
    int x;
    int y;

    x = 0;
    y = 0;
    printf("%lf\n", data->pos_player.x);
    if (keypress == 100)
        data->pos_player.x += 1;
    if (keypress == 97)
        data->pos_player.x -= 1;
    if (keypress == 119)
        data->pos_player.y -= 1;
    if (keypress == 115)
        data->pos_player.y += 1;
    printf("%lf\n", data->pos_player.x);
    if (data->map[(int)data->pos_player.y][(int)data->pos_player.x] == 'N')
        return (0);
    while (data->map[y])
    {
        x = 0;
        while (data->map[y][x])
        {
            if (data->map[y][x] == 'N')
            {
                data->map[y][x] = '0';
                data->map[(int)data->pos_player.y][(int)data->pos_player.x] = 'N';
            }
            x++;
        }
        y++;
    }
    ft_render(data, 0, 0);
    return (0);
}

int init_my_mlx(t_game *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        return (1);
    data->mlx_window = mlx_new_window(data->mlx_ptr, RESOLUTION_L, RESOLUTION_H, NAME_WINDOW);
    if (!data->mlx_window)
        return (free(data->mlx_ptr), 1);
    data->frame.img = mlx_new_image(data->mlx_ptr, RESOLUTION_L, RESOLUTION_H);
    if (!data->frame.img)
        return (free(data->mlx_ptr), 1);
    data->frame.data = mlx_get_data_addr(data->frame.img, &data->frame.bpp, &data->frame.size_line, &data->frame.endian);
     
    ft_render(data, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_window, data->frame.img, 0, 0);
    mlx_hook(data->mlx_window, 2, 1L<<0, hook_key, data);
    return (0);
}
