/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   INIT.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:45:37 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/24 13:53:32 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void ft_init_data(t_game *data)
{
	data->NO = NULL;
	data->EA = NULL;
	data->WE = NULL;
	data->SO = NULL;
	data->F = NULL;
	data->C = NULL;
	//-------------------
	init_hook(data);
	data->mlx_ptr = NULL;
	data->mlx_window = NULL;
	data->angle_initiale = 'N';
	data->TextureName = NULL;
	data->split = NULL;
}
