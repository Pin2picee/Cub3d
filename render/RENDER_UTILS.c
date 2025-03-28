/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER_UTILS.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:23:42 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 17:15:14 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void	draw_wall(int x, int y, int color, t_game *data)
{
	int	i;

	i = 0;
	while (i < 10)
		put_pixel(x + i++, y, color, data);
	i = 0;
	while (i < 10)
		put_pixel(x, y + i++, color, data);
	i = 0;
	while (i < 10)
		put_pixel(x + i++, y + 10, color, data);
	i = 0;
	while (i < 10)
		put_pixel(x + 10, y + i++, color, data);
}

void	draw_square(int x, int y, int color, t_game *data)
{
	int	i;

	i = 0;
	while (i < 5)
		put_pixel(x + i++ - 5 / 2, y - 5 / 2, color, data);
	i = 0;
	while (i < 5)
		put_pixel(x - 5 / 2, y + i++ - 5 / 2, color, data);
	i = 0;
	while (i < 5)
		put_pixel(x + i++ - 5 / 2, y + 5 / 2, color, data);
	i = 0;
	while (i < 5)
		put_pixel(x + 5 / 2, y + i++ - 5 / 2, color, data);
}

void	clean_img(t_game *data)
{
	int	x;
	int	y;

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

void	map_render(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_wall(x * 10, y * 10, BLEU, data);
			x++;
		}
		y++;
	}
}

double	v_absolue(double nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
