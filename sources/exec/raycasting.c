/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:21 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/30 12:23:42 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	cub_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_cub3d *data, int x, int draw_start, t_dda dda)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		cub_pixel_put(&data->img, x, y, data->ceiling_color);
		y++;
	}
	y = dda.draw_end;
	while (y < data->res_y)
	{
		cub_pixel_put(&data->img, x, y, data->floor_color);
		y++;
	}
}

void	draw_wall(t_cub3d *data, t_dda dda, int x)
{
	while (dda.draw_start < dda.draw_end)
	{
		cub_pixel_put(&data->img, x, dda.draw_start, 0xFFFFFF);
		dda.draw_start++;
	}
}

void	raycast_helper(t_cub3d *data, t_ray *ray, t_dda *dda, int x)
{
	ray->camera_x = 2.0 * x / data->res_x - 1;
	ray->ray_dir.x = data->map->player.x_dir + data->map->player.plane_x * ray->camera_x;
	ray->ray_dir.y = data->map->player.y_dir + data->map->player.plane_y * ray->camera_x;
	dda_algo(data, ray, dda);
	dda->line_height = (int)(data->res_y / dda->perp_wall_dist);
	dda->draw_start = (int)(-dda->line_height / 2.0) + ((int)data->res_y / 2.0);
}

#include <unistd.h>

int	raycasting(void *param)
{
	t_ray	ray;
	t_dda	dda;
	int		x;
	t_cub3d	*data;

	x = 0;
	data = (t_cub3d *)param;
	player_interaction(data);
	while (x < data->res_x)
	{
		raycast_helper(data, &ray, &dda, x);
		dda.draw_start = (int)(data->res_y / 2) - (int)(dda.line_height / 2);
		if (dda.draw_start < 0)
			dda.draw_start = 0;
		dda.draw_end = (int)(dda.line_height / 2) + (int)(data->res_y / 2);
		if (dda.draw_end >= data->res_y)
			dda.draw_end = data->res_y - 1;
		draw_line(data, x, dda.draw_start, dda);
		draw_wall(data, dda, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (0);
}
