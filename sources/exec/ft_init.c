/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/24 17:31:10 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_player(t_cub3d *data)
{
	if (data->map->player.spawn_direction == NORTH)
		data->map->player.angle = -M_PI_2;
	else if (data->map->player.spawn_direction == SOUTH)
		data->map->player.angle = M_PI_2;
	else if (data->map->player.spawn_direction == EAST)
		data->map->player.angle = 0.0;
	else if (data->map->player.spawn_direction == WEST)
		data->map->player.angle = M_PI;
	data->map->player.x_dir = cos(data->map->player.angle);
	data->map->player.y_dir = sin(data->map->player.angle);
	data->map->player.plane_x = cos(data->map->player.angle + M_PI_2);
	data->map->player.plane_y = sin(data->map->player.angle + M_PI_2);
	data->map->player.x_pos = data->map->player.location.x + 0.5;
	data->map->player.y_pos = data->map->player.location.y + 0.5;
}

int	ft_init(t_cub3d *data)
{
	data->res_x = 1920;
	data->res_y = 1080;
	init_player(data);
	data->window = mlx_new_window(data->mlx, data->res_x, data->res_y, "Cub3D");
	if (!data->window)
		return (free_and_exit(data), 1);
	data->img.img = mlx_new_image(data->mlx, data->res_x, data->res_y);
	if (!data->img.img)
		return (free_and_exit(data), 1);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (free_and_exit(data), 1);
	return (0);
}
