/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:22 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/30 14:31:06 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	move_forward(t_cub3d *data)
{
	float	x;
	float	y;

	x = data->map->player.x_pos + data->map->player.x_dir * MOVE_SPEED;
	y = data->map->player.y_pos + data->map->player.y_dir * MOVE_SPEED;
	if (data->map->map[(int)data->map->player.y_pos][(int)x] != '1')
		data->map->player.x_pos += data->map->player.x_dir * MOVE_SPEED;
	if (data->map->map[(int)y][(int)data->map->player.x_pos] != '1')
		data->map->player.y_pos += data->map->player.y_dir * MOVE_SPEED;
}

void	move_backward(t_cub3d *data)
{
	float	x;
	float	y;

	x = data->map->player.x_pos - data->map->player.x_dir * MOVE_SPEED;
	y = data->map->player.y_pos - data->map->player.y_dir * MOVE_SPEED;
	if (data->map->map[(int)data->map->player.y_pos][(int)x] != '1')
		data->map->player.x_pos -= data->map->player.x_dir * MOVE_SPEED;
	if (data->map->map[(int)y][(int)data->map->player.x_pos] != '1')
		data->map->player.y_pos -= data->map->player.y_dir * MOVE_SPEED;
}

void	move_left(t_cub3d *data)
{
	float	x;
	float	y;

	x = data->map->player.x_pos + data->map->player.y_dir * MOVE_SPEED;
	y = data->map->player.y_pos - data->map->player.x_dir * MOVE_SPEED;
	if (data->map->map[(int)data->map->player.y_pos][(int)x] != '1')
		data->map->player.x_pos += data->map->player.y_dir * MOVE_SPEED;
	if (data->map->map[(int)y][(int)data->map->player.x_pos] != '1')
		data->map->player.y_pos -= data->map->player.x_dir * MOVE_SPEED;
}

void	move_right(t_cub3d *data)
{
	float	x;
	float	y;

	x = data->map->player.x_pos - data->map->player.y_dir * MOVE_SPEED;
	y = data->map->player.y_pos + data->map->player.x_dir * MOVE_SPEED;
	if (data->map->map[(int)data->map->player.y_pos][(int)x] != '1')
		data->map->player.x_pos -= data->map->player.y_dir * MOVE_SPEED;
	if (data->map->map[(int)y][(int)data->map->player.x_pos] != '1')
		data->map->player.y_pos += data->map->player.x_dir * MOVE_SPEED;
}
