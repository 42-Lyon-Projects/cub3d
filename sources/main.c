/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:08:11 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/22 14:24:50 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string_utils.h>

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		return_state;
	int		value;

	if (argc < 2)
		return (printf("Error\n -> Invalid number of arguments.\n"), 0);
	return_state = handle_file_error(argv);
	if (return_state < 0)
		return (0);
	cub3d.map.path = argv[1];
	cub3d.map.map = NULL;
	load_file_content(&cub3d);
	value = init_graphics_part(&cub3d);
	if (value == -1)
		return (printf("Error\n -> Can't initialize mlx.\n"), 0);
	load_map(&cub3d, value);
	if (!map_is_valid(&cub3d))
		return (printf("Error\n -> Invalid map.\n"), free_and_exit(&cub3d), 0);
	if (ft_init(&cub3d))
		return (printf("Error\n -> Error initializing the game.\n"), free_and_exit(&cub3d), 0);
	free_and_exit(&cub3d);
}

void	free_and_exit(t_cub3d *cub3d)
{
	if (cub3d->file_content != NULL)
		ft_free_split(cub3d->file_content);
	if (cub3d->map.map != NULL)
		ft_free_split(cub3d->map.map);
	destroy_textures(cub3d);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	exit(0);
}
