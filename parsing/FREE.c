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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return ;
}

void	free_data(t_game *data)
{
	if (data->texture_name)
		free_tab(data->texture_name);
	if (data->split)
		free_tab(data->split);
	if (data->mlx_window)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_window);
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
	}
	if (data->so_t.img)
		mlx_destroy_image(data->mlx_ptr, data->so_t.img);
	if (data->no_t.img)
		mlx_destroy_image(data->mlx_ptr, data->no_t.img);
	if (data->ea_t.img)
		mlx_destroy_image(data->mlx_ptr, data->ea_t.img);
	if (data->we_t.img)
		mlx_destroy_image(data->mlx_ptr, data->we_t.img);
	if (data->frame.img)
		mlx_destroy_image(data->mlx_ptr, data->frame.img);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
