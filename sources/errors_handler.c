/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:30:48 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:06:14 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	handle_file_error(char *argv[])
{
	int	fd;

	if (!argv[1])
		return (printf("Error\n -> Invalid file path.\n"), -2);
	if (!ft_endwith(argv[1], ".cub"))
		return (printf("Error\n -> Invalid file format.\n"), -2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n -> Can't open file.\n");
		printf("please check permissions or path: %s\n", argv[1]);
		return (-2);
	}
	return (close(fd), exit(1), fd);
}

