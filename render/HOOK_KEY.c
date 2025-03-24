/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HOOK_KEY.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelmoha <abelmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:24:22 by abelmoha          #+#    #+#             */
/*   Updated: 2025/03/24 17:44:45 by abelmoha         ###   ########.fr       */
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
	if (keypress == S)
		data->key_down = false;
	if (keypress == D)
		data->key_right = false;
	if (keypress == A)
		data->key_left = false;
	if (keypress == rotate_left)
		data->key_rotate_left = false;
	if (keypress == rotate_right)
		data->key_rotate_right = false;
	return (0);
}

int key_press(int keypress, t_game *data)
{   
	if (keypress == W)
		data->key_up = true;
	if (keypress == S)
		data->key_down = true;
	if (keypress == D)
		data->key_right = true;
	if (keypress == A)
		data->key_left = true;
	if (keypress == rotate_left)
		data->key_rotate_left = true;
	if (keypress == rotate_right)
		data->key_rotate_right = true;
	//printf("%d\n", keypress);
	return (0);
}

void    move_player(t_game *data)
{
	double cos_angle;
	double sin_angle;
	t_point current;
	
	current = data->pos_player;
	sin_angle = sin(data->player_angle);
	cos_angle = cos(data->player_angle);
	if (data->key_up == true)
	{
		current.x += (cos_angle * 0.1);
		current.y += (sin_angle * 0.1);
	}
	if (data->key_down == true)
	{
		current.x -= cos_angle * 0.1;
		current.y -= sin_angle * 0.1;
	}
	if (data->key_right == true)
	{
		current.x -=  sin_angle * 0.1;
		current.y += cos_angle * 0.1;
	}
	if (data->key_left == true)
	{
		current.x += sin_angle * 0.1;
		current.y -= cos_angle * 0.1;
	}
	if (data->key_rotate_left)
		data->player_angle -= 0.05;
	if (data->key_rotate_right)
		data->player_angle += 0.05;
	if (data->player_angle > PI * 2)
		data->player_angle = 0;
	if (data->player_angle < 0)
		data->player_angle = PI * 2;
	if (data->map[(int)current.y][(int)current.x] == '1')
		return ;
	data->pos_player.x = current.x;
	data->pos_player.y = current.y;
}
