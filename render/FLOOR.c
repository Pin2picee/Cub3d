/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FLOOR.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:54:24 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/27 18:30:29 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

int	get_hexa(int r, int v, int b)
{
	unsigned long hexa;

	hexa = (r << 16) | (v << 8) | (b);

	return ((int)hexa);
}


int	ft_get_color_key(char *str)
{
	int		i;
	int		j;
	int		index;
	char	color[4];
	int		couleur[3];
	
	i = 0;
	j = 0;
	index = 0;
	//TODO:aller chercher le premier nombre puis le deuxieme puis le 3 eme
	while (i < (int)ft_strlen(str) && str[i])
	{
		ft_bzero(color, 4);
		j = 0;
		while (j <= i && i < (int)ft_strlen(str) && str[i] != ',')
		{
			color[j] = str[i++];
			j++;
		}
		if (index < 3)
			couleur[index++] = ft_atoi(color);
		if (i < (int)ft_strlen(str) && str[i] == ',')
			i++;
	}
	return (get_hexa(couleur[0], couleur[1], couleur[2]));
}

// recupere pour les deux cles les 3 nombres, transformer en hexa

void   floor_and_ceiling(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < RESOLUTION_H / 2)
	{
		x = 0;
		while (x < RESOLUTION_L)
		{
			put_pixel(x, y, data->ceiling, data);
			x++;
		}
		y++;
	}
	while (y < RESOLUTION_H)
	{
		x = 0;
		while (x < RESOLUTION_L)
		{
			put_pixel(x, y, data->floor, data);
			x++;
		}
		y++;
	}
}
