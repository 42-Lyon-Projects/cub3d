/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:21 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/23 15:48:32 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_line(t_cub3d *data, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		data->img.addr[y * (int)data->res_y + x] = data->ceiling_color;
		y++;
	}
	while (y < data->res_y)
	{
		data->img.addr[y * (int)data->res_y + x] = data->floor_color;
		y++;
	}
}

void	raycast_helper(t_cub3d *data, t_ray *ray, t_dda *dda, int x)
{
	ray->camera_x = 2.0 * x / data->res_x - 1;
	ray->ray_dir.x = data->map.player.x_dir + data->map.player.plane_x * ray->camera_x;
	ray->ray_dir.y = data->map.player.y_dir + data->map.player.plane_y * ray->camera_x;
	dda_algo(data, ray, dda);
	dda->line_height = (int)(data->res_y / dda->perp_wall_dist);
	dda->draw_start = (int)(-dda->line_height / 2.0) + ((int)data->res_y / 2.0);
}

int	raycasting(void *param)
{
	t_ray	ray;
	t_dda	dda;
	int		x;
	t_cub3d	*data;

	x = 0;
	data = (t_cub3d *)param;
	while (x < data->res_x)
	{
		raycast_helper(data, &ray, &dda, x);
		if (dda.draw_start < 0)
			dda.draw_start = 0;
		dda.draw_end = (int)(dda.line_height / 2) + (int)(data->res_y / 2);
		if (dda.draw_end >= data->res_y)
			dda.draw_end = data->res_y - 1;
		draw_line(data, x, dda.draw_start);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img.img, 0, 0);
	return (0);
}
