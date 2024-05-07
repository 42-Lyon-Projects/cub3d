/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:42 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/07 10:17:42 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include "put_utils.h"

t_boolean	map_is_open(char **map)
{
	ssize_t	x;
	ssize_t	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (set_contains_char(map[y][x], "NSEW0"))
			{
				if (!map[y][x + 1] || map[y][x + 1] == ' ')
					return (ft_putstr_fd("Error\n -> Map not closed.\n", 2), 1);
				if (map[y + 1] == NULL || !map[y + 1][x] || \
				map[y + 1][x] == ' ')
					return (ft_putstr_fd("Error\n -> Map not closed.\n", 2), 1);
				if ((x && (!map[y][x - 1] || map[y][x - 1] == ' ')) || !x)
					return (ft_putstr_fd("Error\n -> Map not closed.\n", 2), 1);
				if ((y && (map[y - 1] == NULL || !map[y - 1][x] \
					|| map[y - 1][x] == ' ')) || !y)
					return (ft_putstr_fd("Error\n -> Map not closed.\n", 2), 1);
			}
		}
	}
	return (_false);
}
