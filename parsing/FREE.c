/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FREE.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:23:52 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/18 18:23:52 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void    free_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return ;
}


void    free_data(t_game *data)
{
	if (data->TextureName)
		free_tab(data->TextureName);
	// on free la map via le split de ma data car j'ai fait un pointeur vers le debut de la map
	if (data->split)
		free_tab(data->split);
	if (data->mlx_window)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	}
	if (data->SO_t.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->SO_t.img);
	}
	if (data->NO_t.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->NO_t.img);
	}
	if (data->EA_t.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->EA_t.img);
	}	
	if (data->WE_t.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->WE_t.img);
	}
	if (data->frame.img)
	{
		mlx_destroy_image(data->mlx_ptr, data->frame.img);
	}
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
