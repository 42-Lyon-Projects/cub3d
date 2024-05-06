/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:08:11 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/06 14:01:17 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string_utils.h>
#include <put_utils.h>

void	hooks(t_cub3d *data)
{
	raycasting(data);
	mlx_hook(data->window, 17, 1L << 0, close_window, data);
	mlx_hook(data->window, 2, 1L << 0, key_press, data);
	mlx_hook(data->window, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, raycasting, data);
	mlx_loop(data->mlx);
}

static void init_null(t_cub3d *cub3d)
{
	cub3d->map->map = NULL;
	cub3d->img.img = NULL;
	cub3d->mlx = NULL;
	cub3d->window = NULL;
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		return_state;
	int		value;

	if (argc != 2)
		return (ft_putstr_fd("Error\n -> Invalid number of arguments.\n", 2), 0);
	return_state = handle_file_error(argv);
	if (return_state < 0)
		return (0);
	cub3d.map = malloc(sizeof(t_map));
	if (cub3d.map == NULL)
		return (ft_putstr_fd("Error\n -> Can't load map.\n", 2), 0);
	cub3d.map->path = argv[1];
	init_null(&cub3d);
	load_file_content(&cub3d);
	value = init_graphics_part(&cub3d);
	if (value == -1)
		return (ft_putstr_fd("Error\n -> Can't initialize mlx.\n", 2), 0);
	load_map(&cub3d, value);
	if (!map_is_valid(&cub3d))
		return (ft_putstr_fd("Error\n -> Invalid map.\n", 2), free_and_exit(&cub3d), 0);
	if (map_is_open(cub3d.map->map))
		return (free_and_exit(&cub3d), 0);
	if (ft_init(&cub3d))
		return (ft_putstr_fd("Error\n -> Error initializing the game.\n", 2), free_and_exit(&cub3d), 0);
	hooks(&cub3d);
}

void	free_and_exit(t_cub3d *cub3d)
{
	ft_free_split(cub3d->file_content);
	ft_free_split(cub3d->map->map);
	destroy_textures(cub3d);
	free(cub3d->map);
	if (cub3d->mlx)
	{
		if (cub3d->img.img)
			mlx_destroy_image(cub3d->mlx, cub3d->img.img);
		if (cub3d->window)
			mlx_destroy_window(cub3d->mlx, cub3d->window);
		mlx_destroy_display(cub3d->mlx);
		free(cub3d->mlx);
	}
	exit(0);
}
