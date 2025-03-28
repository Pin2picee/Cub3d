/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PARSING_HELP.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:32:41 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 17:13:58 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int	check_exist(t_game *data, int i, int j)
{
	int		count;

	count = 0;
	while (data->split[j] && count < 6)
	{
		i = -1;
		while (data->texture_name[++i])
		{
			if (!ft_strncmp(data->split[j], data->texture_name[i],
					ft_strlen(data->texture_name[i])))
			{
				count++;
				break ;
			}
			if (i == 5)
				return (1);
		}
		j++;
	}
	while (ft_line_empty(data->split[j]))
		j++;
	data->index = j;
	if (count < 5 || check_already_exist(data))
		return (1);
	return (0);
}
