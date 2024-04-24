/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:49:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/24 17:44:27 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "stdlib.h"

int	close_window(t_cub3d *data)
{
	exit(0);
//	free_and_exit(data);
}

int	key_press(int key, t_cub3d *data)
{
	if (key == LEFT)
		cam_rotate_left(data);
	else if (key == RIGHT)
		cam_rotate_right(data);
	else if (key == W)
		move_forward(data);
	else if (key == S)
		move_backward(data);
	else if (key == A)
		move_left(data);
	else if (key == D)
		move_right(data);
	else if (key == ESC)
		free_and_exit(data);
	return (0);
}

//int	key_release(int key, t_cub3d *data)
//{
//	if (key == 53 && data)
//		exit(0);
//	return (0);
//}