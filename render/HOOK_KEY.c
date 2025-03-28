/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HOOK_KEY.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:24:22 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/28 17:49:20 by abelmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/LIB.h"

void	init_hook(t_game *data)
{
	data->key_down = false;
	data->key_up = false;
	data->key_left = false;
	data->key_right = false;
	data->key_rotate_left = false;
	data->key_rotate_right = false;
	data->key_esc = false;
	data->key_speed = false;
}

int	key_reset(int keypress, t_game *data)
{
	if (keypress == W)
		data->key_up = false;
	if (keypress == S)
		data->key_down = false;
	if (keypress == D)
		data->key_right = false;
	if (keypress == A)
		data->key_left = false;
	if (keypress == ROTATE_LEFT)
		data->key_rotate_left = false;
	if (keypress == ROTATE_RIGHT)
		data->key_rotate_right = false;
	if (keypress == SHIFT)
		data->key_speed = false;
	return (0);
}

int	key_press(int keypress, t_game *data)
{
	if (keypress == W)
		data->key_up = true;
	if (keypress == S)
		data->key_down = true;
	if (keypress == D)
		data->key_right = true;
	if (keypress == A)
		data->key_left = true;
	if (keypress == ROTATE_LEFT)
		data->key_rotate_left = true;
	if (keypress == ROTATE_RIGHT)
		data->key_rotate_right = true;
	if (keypress == ESC)
		data->key_esc = true;
	if (keypress == SHIFT)
		data->key_speed = true;
	return (0);
}

void	move_player_2(t_game *data, double *speed, double *si, double *co)
{
	*speed = SPEEDRUN;
	*si = sin(data->player_angle);
	*co = cos(data->player_angle);
	if (data->key_esc == true)
	{
		free_data(data);
		exit(0);
	}
	if (data->key_speed)
		*speed = SPEEDRUN + 0.1;
	if (data->key_rotate_left)
		data->player_angle -= SPEEDROTATE;
	if (data->key_rotate_right)
		data->player_angle += SPEEDROTATE;
	if (data->player_angle > PI * 2)
		data->player_angle = 0;
	if (data->player_angle < 0)
		data->player_angle = PI * 2;
	if (data->key_up == true)
	{
		data->current.x += (*co * *speed);
		data->current.y += (*si * *speed);
	}
}

void	move_player(t_game *data, double cos_a, double sin_a, double speed)
{
	data->current = data->pos_player;
	move_player_2(data, &speed, &sin_a, &cos_a);
	if (data->key_down == true)
	{
		data->current.x -= cos_a * speed;
		data->current.y -= sin_a * speed;
	}
	if (data->key_right == true)
	{
		data->current.x -= sin_a * speed;
		data->current.y += cos_a * speed;
	}
	if (data->key_left == true)
	{
		data->current.x += sin_a * speed;
		data->current.y -= cos_a * speed;
	}
	if (data->map[(int)data->current.y][(int)data->current.x] == '1')
		return ;
	data->pos_player.x = data->current.x;
	data->pos_player.y = data->current.y;
}
