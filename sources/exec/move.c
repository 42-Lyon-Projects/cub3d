/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:51:22 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/24 17:31:10 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub3d *data)
{
	data->map->player.x_pos += data->map->player.x_dir * MOVE_SPEED;
	data->map->player.y_pos += data->map->player.y_dir * MOVE_SPEED;
}

void	move_backward(t_cub3d *data)
{
	data->map->player.x_pos -= data->map->player.x_dir * MOVE_SPEED;
	data->map->player.y_pos -= data->map->player.y_dir * MOVE_SPEED;
}

void	move_left(t_cub3d *data)
{
	data->map->player.x_pos += data->map->player.y_dir * MOVE_SPEED;
	data->map->player.y_pos -= data->map->player.x_dir * MOVE_SPEED;
}

void	move_right(t_cub3d *data)
{
	data->map->player.x_pos -= data->map->player.y_dir * MOVE_SPEED;
	data->map->player.y_pos += data->map->player.x_dir * MOVE_SPEED;
}
