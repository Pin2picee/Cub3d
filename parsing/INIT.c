/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INIT.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:37 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 17:53:34 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void	ft_init_img(t_game *data)
{
	data->no_t.img = NULL;
	data->so_t.img = NULL;
	data->ea_t.img = NULL;
	data->we_t.img = NULL;
	data->frame.img = NULL;
}

void	ft_init_data(t_game *data)
{
	data->no = NULL;
	data->ea = NULL;
	data->we = NULL;
	data->so = NULL;
	data->f = NULL;
	data->c = NULL;
	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
	data->angle_initiale = 'N';
	data->texture_name = NULL;
	data->split = NULL;
	ft_init_img(data);
	init_hook(data);
}
