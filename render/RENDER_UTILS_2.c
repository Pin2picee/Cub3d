/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RENDER_UTILS_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:09:45 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 16:01:07 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int	ft_check_verti(double x, double y)
{
	(void)y;
	if (fabs(x - round(x)) <= 0.01)
		return (42);
	return (0);
}

int	ft_check_horizon(double x, double y)
{
	(void)x;
	if (fabs(y - round(y)) <= 0.01)
		return (42);
	return (0);
}

double	get_distance_rayon(double x_1, double x_2, double y_1, double y_2)
{
	double	distance_rayon;

	distance_rayon = pow(v_absolue(x_1 - x_2), 2)
		+ pow(v_absolue(y_1 - y_2), 2);
	distance_rayon = sqrt(distance_rayon);
	return (distance_rayon);
}

void	what_texture(t_game *d, double start_angle)
{
	int	verti;
	int	horizon;

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

void	info_recast(t_game *d, double start_angle)
{
	d->dist_rayon = get_distance_rayon(d->r_x, d->pos_player.x,
			d->r_y, d->pos_player.y);
	d->wall_size = ((double)WALL_SIZE / d->dist_rayon) * (d->map_height / 2)
		/ cos(d->player_angle - start_angle);
	d->start_y = (RESOLUTION_H - d->wall_size) / 2 - 1;
	d->finish = d->start_y + d->wall_size;
}
