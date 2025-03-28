/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAP.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:30:34 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 15:06:23 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

/*
=====================
	Recursivite
	Pour aller tous
	les endroits 
	accessible
=====================
*/

void	fill_2(t_game *game, char **map_copy, t_point current)
{
	fill(game, map_copy, (t_point){current.x + 1, current.y});
	fill(game, map_copy, (t_point){current.x - 1, current.y});
	fill(game, map_copy, (t_point){current.x, current.y + 1});
	fill(game, map_copy, (t_point){current.x, current.y - 1});
	fill(game, map_copy, (t_point){current.x - 1, current.y - 1});
	fill(game, map_copy, (t_point){current.x + 1, current.y + 1});
	fill(game, map_copy, (t_point){current.x + 1, current.y - 1});
	fill(game, map_copy, (t_point){current.x + 1, current.y - 1});
}

void	fill(t_game *game, char **map_copy, t_point current)
{
	if (current.x < 0 || current.y < 0
		|| current.x >= (double)ft_strlen(map_copy[(int)current.y])
		|| current.y >= game->map_height
		|| map_copy[(int)current.y][(int)current.x] == 'F'
		|| map_copy[(int)current.y][(int)current.x] == '1')
		return ;
	if (map_copy[(int)current.y][(int)current.x] == ' ' || (((int)current.x == 0
		|| (int)current.x == (int)ft_strlen(map_copy[(int)current.y]) - 1
		|| (int)current.y == 0 || (int)current.y == game->map_height - 1))
		|| !map_copy[(int)current.y - 1][(int)current.x - 1]
		|| !map_copy[(int)current.y + 1][(int)current.x + 1]
		|| !map_copy[(int)current.y - 1][(int)current.x + 1]
		|| !map_copy[(int)current.y + 1][(int)current.x - 1])
	{
		game->flags = 1;
		return ;
	}
	else if (map_copy[(int)current.y][(int)current.x] == '0'
		|| map_copy[(int)current.y][(int)current.x] == 'N'
		|| map_copy[(int)current.y][(int)current.x] == 'S'
		|| map_copy[(int)current.y][(int)current.x] == 'E'
		|| map_copy[(int)current.y][(int)current.x] == 'W')
		map_copy[(int)current.y][(int)current.x] = 'F';
	fill_2(game, map_copy, current);
}

/*
=========================
	Determine l'angle du 
	joueur au debut
=========================
*/
void	do_angle_for_player(t_game *data)
{
	if (data->angle_initiale == 'N')
		data->player_angle = PI / 2;
	else if (data->angle_initiale == 'S')
		data->player_angle = (3 * PI) / 2;
	else if (data->angle_initiale == 'W')
		data->player_angle = PI;
	else if (data->angle_initiale == 'E')
		data->player_angle = 0;
}

int	parse_map(t_game *data)
{
	char	**copy;

	info_map(data);
	copy = copy_map(data->map, data->map_height);
	if (!copy || check_elements(data))
		return (1);
	fill(data, copy, data->pos_player);
	free_tab(copy);
	if (data->flags)
		return (1);
	do_angle_for_player(data);
	return (0);
}
