/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:48:50 by lunagda           #+#    #+#             */
/*   Updated: 2024/05/06 14:34:13 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "math.h"

void	sidestep_dist(t_cub3d *data, t_ray *ray, t_dda *dda)
{
	if (ray->ray_dir.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist.x = (data->map->player.x_pos - dda->map_x)
			* dda->delta_dist.x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist.x = (dda->map_x + 1.0 - data->map->player.x_pos)
			* dda->delta_dist.x;
	}
	if (ray->ray_dir.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist.y = (data->map->player.y_pos - dda->map_y)
			* dda->delta_dist.y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist.y = (dda->map_y + 1.0 - data->map->player.y_pos)
			* dda->delta_dist.y;
	}
}

void	dda_algo_helper(t_cub3d *data, t_ray *ray, t_dda *dda)
{
	dda->map_x = (int)data->map->player.x_pos;
	dda->map_y = (int)data->map->player.y_pos;
	dda->delta_dist.x = 1e30;
	if (dda->delta_dist.x != 0)
		dda->delta_dist.x = fabs(1.0 / ray->ray_dir.x);
	dda->delta_dist.y = 1e30;
	if (dda->delta_dist.y != 0)
		dda->delta_dist.y = fabs(1.0 / ray->ray_dir.y);
	sidestep_dist(data, ray, dda);
}

void	dda_algo(t_cub3d *data, t_ray *ray, t_dda *dda)
{
	dda_algo_helper(data, ray, dda);
	dda->hit = 0;
	while (dda->hit == 0)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		if (data->map->map[dda->map_y][dda->map_x] == '1')
			dda->hit = 1;
		else
			dda->hit = 0;
	}
	if (dda->side == 0)
		dda->perp_wall_dist = dda->side_dist.x - dda->delta_dist.x;
	else
		dda->perp_wall_dist = dda->side_dist.y - dda->delta_dist.y;
}
