/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:08:11 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 10:22:09 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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
	free_and_exit(&game);
}

void free_and_exit(t_cub3d *cub3d)
{
	destroy_textures(cub3d);
	mlx_destroy_display(cub3d->mlx);
	free(cub3d->mlx);
	exit(0);
}
