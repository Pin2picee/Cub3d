/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   UTILS_PARSING_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 00:57:01 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/17 00:57:01 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"
/*
=================================
		Fonction qui check si le nombre des colors et pas < 0 && > 256

		A FINIR
=================================
*/

int	ft_position(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'E' || game->map[i][j] == 'S' || game->map[i][j] == 'W')
			{
				count++;
				game->angle_initiale = game->map[i][j];
				game->pos_player.y = (double)i + 0.5;
				game->pos_player.x = (double)j + 0.5;
			}
			j++;
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

int	limit_number_rgb(char *str)
{
	char	color[4];
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	if (!str)
		return (1);
	while (str && str[i] )
	{
		ft_bzero(color, sizeof(color));
		j = 0;
		while (str[i] && str[i] != ',')
		{

			if (j >= 3)
				return (1);
			color[j] = str[i];
			j++;
			i++;
		}
		if (str[i] == ',')
				count++;
		if (ft_atoi(color) > 255 || ft_atoi(color) < 0)
			return (1);
		if (str[i])
			i++;
	}
	if (count != 2)
		return (1);
	return (0);

}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	i = -1;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
	{
		return (NULL);
	}
	while (++i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			if (copy != NULL)
				free(copy);
			return (NULL);
		}
	}
	copy[i] = NULL;
	return (copy);
}