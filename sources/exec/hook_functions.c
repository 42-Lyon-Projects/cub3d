/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:49:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/30 12:23:18 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdlib.h"

int	close_window(t_cub3d *data)
{
	free_and_exit(data);
}

int	key_press(int key, t_cub3d *data)
{
	if (key == LEFT)
		data->keys.left = _true;
	else if (key == RIGHT)
		data->keys.right = _true;
	else if (key == W)
		data->keys.w = _true;
	else if (key == S)
		data->keys.s = _true;
	else if (key == A)
		data->keys.a = _true;
	else if (key == D)
		data->keys.d = _true;
	else if (key == ESC)
		free_and_exit(data);
	return (0);
}

int	key_release(int key, t_cub3d *data)
{
	if (key == LEFT)
		data->keys.left = _false;
	else if (key == RIGHT)
		data->keys.right = _false;
	else if (key == W)
		data->keys.w = _false;
	else if (key == S)
		data->keys.s = _false;
	else if (key == A)
		data->keys.a = _false;
	else if (key == D)
		data->keys.d = _false;
	return (0);
}

void	player_interaction(t_cub3d *data)
{
	if (data->keys.left)
		cam_rotate_left(data);
	if (data->keys.right)
		cam_rotate_right(data);
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
}
