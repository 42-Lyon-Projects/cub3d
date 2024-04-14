/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 19:08:11 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:16:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	t_cub3d	game;

	if (argc != 1)
		return (printf("Error\n -> Invalid number of arguments.\n"), 0);
	handle_file_error(argv);
	game.map.path = argv[1];
	int value = init_graphics_part(&game);
	if (value == -1)
		return (printf("Error\n -> Can't initialize graphics.\n"), 0);
	load_config(&game);

}
