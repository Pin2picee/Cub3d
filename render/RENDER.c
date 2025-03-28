/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 10:13:24 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 18:03:31 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void	put_pixel(int x, int y, int color, t_game *data)
{
	int	index;

	if (x > RESOLUTION_L || x < 0 || y > RESOLUTION_H || y < 0)
		return ;
	index = y * data->frame.size_line + x * data->frame.bpp / 8;
	data->frame.data[index] = color & 0xFF;
	data->frame.data[index + 1] = (color >> 8) & 0xFF;
	data->frame.data[index + 2] = (color >> 16) & 0xFF;
}

/*
===================================
		Projete un rayon 
		puis dessine le mur de haut en bas
===================================
*/
void	project_rayon(t_game *d, double start_angle, int i, int color)
{
	int		texture_x;
	int		texture_y;
	double	ratio;

	d->r_x = d->pos_player.x;
	d->r_y = d->pos_player.y;
	while (d->map[(int)d->r_y][(int)d->r_x] != '1')
	{
		d->r_x += cos(start_angle) * 0.01;
		d->r_y += sin(start_angle) * 0.01;
	}
	what_texture(d, start_angle);
	info_recast(d, start_angle);
	texture_x = ft_do_x(d);
	ratio = (double)d->tab_img[d->choice]->height / (double)d->wall_size;
	while (++d->start_y < d->finish)
	{
		texture_y = (int)((d->start_y - (RESOLUTION_H - d->wall_size) / 2.0)
				* ratio) % d->tab_img[d->choice]->height;
		if (texture_y < 0)
			texture_y += d->tab_img[d->choice]->height;
		color = *(int *)(d->tab_img[d->choice]->data
				+ (texture_y * d->tab_img[d->choice]->width + texture_x) * 4);
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
void	fov(t_game *data)
{
	double	rayon_start;
	double	increment_rayon;
	int		i;

	i = 0;
	rayon_start = (data->player_angle - (PI / 6));
	increment_rayon = (PI / 3 / RESOLUTION_L);
	while (i < RESOLUTION_L && rayon_start < data->player_angle + PI / 6)
	{
		rayon_start += increment_rayon;
		project_rayon(data, rayon_start, i, 0);
		i++;
	}
}

/*
===================================
			Type fps loop
===================================
*/
int	loop_game(t_game *data)
{
	move_player(data, 0, 0, 0);
	clean_img(data);
	floor_and_ceiling(data);
	fov(data);
	draw_square(data->pos_player.x * 10,
		data->pos_player.y * 10, ROUGE, data);
	map_render(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_window,
		data->frame.img, 0, 0);
	return (0);
}

/*
===================================
		POINT DE DEPART
===================================
*/
int	init_my_mlx(t_game *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	load_texture(data);
	data->mlx_window = mlx_new_window(data->mlx_ptr, RESOLUTION_L,
			RESOLUTION_H, NAME_WINDOW);
	if (!data->mlx_window)
		return (free(data->mlx_ptr), 1);
	data->frame.img = mlx_new_image(data->mlx_ptr, RESOLUTION_L,
			RESOLUTION_H);
	if (!data->frame.img)
		return (free(data->mlx_ptr), 1);
	data->frame.data = mlx_get_data_addr(data->frame.img, &data->frame.bpp,
			&data->frame.size_line, &data->frame.endian);
	init_hook(data);
	mlx_hook(data->mlx_window, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_window, 3, 1L << 1, key_reset, data);
	mlx_hook(data->mlx_window, 17, 0, ft_croix_rouge, data);
	mlx_loop_hook(data->mlx_ptr, loop_game, data);
	return (0);
}
