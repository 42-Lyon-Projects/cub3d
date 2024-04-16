/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:30:48 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 10:34:12 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	handle_file_error(char *argv[])
{
	int	fd;

	if (!argv[1])
		return (printf("Error\n -> Invalid file path.\n"), -1);
	if (!ft_endwith(argv[1], ".cub"))
		return (printf("Error\n -> Invalid file format.\n"), -2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n -> Can't open file.\n");
		printf("please check permissions or path: %s\n", argv[1]);
		return (-3);
	}
	close(fd);
	return (1);
}

t_boolean textures_has_correctly_loaded(t_cub3d *cub3d)
{
	t_loaded_textures *tmp;
	int index;

	tmp = cub3d->textures;
	index = 0;
	while (tmp != NULL)
	{
		if (tmp->current_texture->texture == NULL)
			return (_false);
		tmp = tmp->next;
		index++;
	}
	if (index != 4)
		return (_false);
	return (_true);
}

