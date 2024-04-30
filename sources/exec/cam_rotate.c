/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:53:58 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/24 17:31:10 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_rotate_left(t_cub3d *data)
{
	data->map->player.angle -= ROTATE_SPEED;
	data->map->player.x_dir = cos(data->map->player.angle);
	data->map->player.y_dir = sin(data->map->player.angle);
	data->map->player.plane_x = cos(data->map->player.angle + M_PI_2);
	data->map->player.plane_y = sin(data->map->player.angle + M_PI_2);
}

void	cam_rotate_right(t_cub3d *data)
{
	data->map->player.angle += ROTATE_SPEED;
	data->map->player.x_dir = cos(data->map->player.angle);
	data->map->player.y_dir = sin(data->map->player.angle);
	data->map->player.plane_x = cos(data->map->player.angle + M_PI_2);
	data->map->player.plane_y = sin(data->map->player.angle + M_PI_2);
}
