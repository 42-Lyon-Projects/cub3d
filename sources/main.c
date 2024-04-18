/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:08:11 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 16:21:35 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static void print_2D_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}


int main(int argc, char **argv)
{
	t_cub3d	game;
	int		return_state;

	if (argc < 2)
		return (printf("Error\n -> Invalid number of arguments.\n"), 0);
	return_state = handle_file_error(argv);
	if (return_state < 0)
		return (0);
	game.map.path = argv[1];
	int value = init_graphics_part(&game);
	if (value == -1)
		return (printf("Error\n -> Can't initialize mlx.\n"), 0);
	parse_map(&game);
	print_2D_map(game.map.map);
	//print_2D_map(ft_floodfill(game.map.map, "10?", 'F', (t_location){1, 1}));

	free_and_exit(&game);
}

void free_and_exit(t_cub3d *cub3d)
{
	int index;

	if (cub3d->map.fd != -1)
		close(cub3d->map.fd);
	destroy_textures(cub3d);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	index = 0;
	while (cub3d->map.map[index])
	{
		free(cub3d->map.map[index]);
		index++;
	}
	free(cub3d->map.map);
	exit(0);
}
