/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAP_UTILS.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:59:09 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 15:24:07 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

/*
================
Donne la Hauteur
================
*/
void	info_map(t_game *data)
{
	int	j;

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
