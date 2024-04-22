/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:17:42 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/22 14:24:28 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init(t_cub3d *data)
{
	data->res_x = 1920;
	data->res_y = 1080;
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
