/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAP.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:30:34 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/22 15:43:35 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void    info_map(t_game *data)
{
	int j;
	
	j = 0;
	while (data->map[j] != NULL)
	{
		j++;
	}
	data->map_height = j;
	return ;
}

int	check_elements(t_game *game)
{
	int		i;
	int		j;
	char	str[8];

	i = -1;
	ft_strlcpy(str, "01NESW ", sizeof(str));
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (!ft_strchr(str, game->map[i][j]))
				return (1);
		}
	}
	if (ft_position(game))
		return (1);
	return (0);
}

void	fill( t_game *game, char **map_copy, t_point current)
{
	if (current.x < 0 || current.y < 0 || current.x >= (double)ft_strlen(map_copy[(int)current.y]) || 
		current.y >= game->map_height || map_copy[(int)current.y][(int)current.x] == 'F'
		|| map_copy[(int)current.y][(int)current.x] == '1')
		return ;
	if (map_copy[(int)current.y][(int)current.x] == ' ' || (map_copy[(int)current.y][(int)current.x] == '0' &&
		((int)current.x == 0 || (int)current.x == (int)ft_strlen(map_copy[(int)current.y]) - 1 ||
			(int)current.y == 0 || (int)current.y == game->map_height - 1)) || !map_copy[(int)current.y - 1][(int)current.x - 1]
			|| !map_copy[(int)current.y + 1][(int)current.x + 1] || !map_copy[(int)current.y - 1][(int)current.x + 1]
			|| !map_copy[(int)current.y + 1][(int)current.x - 1])
	{
		game->flags = 1;
		return ;
	}
	else if (map_copy[(int)current.y][(int)current.x] == '0'
		|| map_copy[(int)current.y][(int)current.x] == 'N' || map_copy[(int)current.y][(int)current.x] == 'S' ||
			 map_copy[(int)current.y][(int)current.x] == 'E' || map_copy[(int)current.y][(int)current.x] == 'W')
		map_copy[(int)current.y][(int)current.x] = 'F';
	fill(game, map_copy, (t_point){current.x + 1, current.y});
	fill(game, map_copy, (t_point){current.x - 1, current.y});
	fill(game, map_copy, (t_point){current.x, current.y + 1});
	fill(game, map_copy, (t_point){current.x, current.y - 1});
	fill(game, map_copy, (t_point){current.x - 1, current.y - 1});
	fill(game, map_copy, (t_point){current.x + 1, current.y + 1});
	fill(game, map_copy, (t_point){current.x + 1, current.y - 1});
	fill(game, map_copy, (t_point){current.x + 1, current.y - 1});
}

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
	printf("angle du joueur est : %f et angle initiale est : %c\n", data->player_angle, data->angle_initiale);
}

int parse_map(t_game *data)
{
	char **copy;
	
	info_map(data);// donne la hauteur
	copy = copy_map(data->map, data->map_height);
	if (check_elements(data))
		return (1);
	fill(data, copy, data->pos_player);
	free_tab(copy);
	if (data->flags)
		return (printf("MIAOUUUU"), 1);
	do_angle_for_player(data);
	return (0);
}

/*

|| !map_copy[(int)current.y - 1][(int)current.x - 1]
			|| !map_copy[(int)current.y + 1][(int)current.x + 1] || !map_copy[(int)current.y - 1][(int)current.x + 1]
			|| !map_copy[(int)current.y + 1][(int)current.x - 1]

*/