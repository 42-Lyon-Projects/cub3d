/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:56:40 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/02 17:06:19 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_wall_textures(t_cub3d *data)
{
	data->wall.img = NULL;
	data->wall.addr = NULL;
	data->wall.line_length = 0;
	data->wall.bits_per_pixel = 0;
	data->wall.endian = 0;
}

void	get_wall_side(t_cub3d *data, t_dda *dda, t_ray *ray)
{
	init_wall_textures(data);
	if (dda->side == 0)
	{
		if (ray->ray_dir.x < 0)
			data->wall.img = get_texture_by_direction(data, WEST)->current_texture->texture;
		else
			data->wall.img = get_texture_by_direction(data, EAST)->current_texture->texture;
	}
	else
	{
		if (ray->ray_dir.y < 0)
			data->wall.img = get_texture_by_direction(data, NORTH)->current_texture->texture;
		else
			data->wall.img = get_texture_by_direction(data, SOUTH)->current_texture->texture;
	}
}

void	texture_prep(t_cub3d *data, t_dda *dda, t_ray *ray)
{
	get_wall_side(data, dda, ray);
	if (dda->side == 0)
		data->wall_x = data->map->player.y_pos + dda->perp_wall_dist * ray->ray_dir.y;
	else
		data->wall_x = data->map->player.x_pos + dda->perp_wall_dist * ray->ray_dir.x;
	//data->wall_x = floor(data->wall_x);
}

int	get_pixel_color(t_cub3d *data, int x, int y)
{
	int		color;
	int		index;

	data->wall.addr = mlx_get_data_addr(data->wall.img, &data->wall.bits_per_pixel, &data->wall.line_length, &data->wall.endian);
	index = (y * data->wall.line_length) + (x * (data->wall.bits_per_pixel / 8));
	color = (*(unsigned int *)(data->wall.addr + index));
	return (color);
}
