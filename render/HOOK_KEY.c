/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HOOK_KEY.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:24:22 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/22 16:20:07 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"


void    init_hook(t_game *data)
{
	data->key_down = false;
	data->key_up = false;
	data->key_left = false;
	data->key_right = false;
	data->key_rotate_left = false;
	data->key_rotate_right = false;
}

int key_reset(int keypress, t_game *data)
{
	if (keypress == W)
		data->key_up = false;
	else if (keypress == S)
		data->key_down = false;
	else if (keypress == D)
		data->key_right = false;
	else if (keypress == A)
		data->key_left = false;
	else if (keypress == rotate_left)
		data->key_rotate_left = false;
	else if (keypress == rotate_right)
		data->key_rotate_right = false;
	return (0);
}

int key_press(int keypress, t_game *data)
{   
	if (keypress == W)
		data->key_up = true;
	else if (keypress == S)
		data->key_down = true;
	else if (keypress == D)
		data->key_right = true;
	else if (keypress == A)
		data->key_left = true;
	else if (keypress == rotate_left)
		data->key_rotate_left = true;
	else if (keypress == rotate_right)
		data->key_rotate_right = true;
	//printf("%d\n", keypress);
	return (0);
}

void    move_player(t_game *data)
{
	double cos_angle;
	double sin_angle;
	
	sin_angle = sin(data->player_angle);
	cos_angle = cos(data->player_angle);
	if (data->key_up == true)
	{
		data->pos_player.x += (cos_angle * 0.1);
		data->pos_player.y += (sin_angle * 0.1);
	}
	else if (data->key_down == true)
	{
		data->pos_player.x -= cos_angle * 0.1;
		data->pos_player.y -= sin_angle * 0.1;
	}
	else if (data->key_right == true)
	{
		data->pos_player.x += cos_angle * 0.1;
		data->pos_player.x -= sin_angle * 0.1;
	}
	else if (data->key_left == true)
	{
		data->pos_player.x -= cos_angle * 0.1;
		data->pos_player.x += sin_angle * 0.1;
	}
	else if (data->key_rotate_left)
		data->player_angle -= 0.05;
	else if (data->key_rotate_right)
		data->player_angle += 0.05;
	if (data->player_angle > PI * 2)
		data->player_angle = 0;
	if (data->player_angle < 0)
		data->player_angle = PI * 2;
	//printf("x : %f\n", data->pos_player.x);
	//printf("y : %f\n", data->pos_player.y);
}