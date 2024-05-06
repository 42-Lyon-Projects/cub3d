/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:45:57 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/06 14:42:53 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "put_utils.h"

static t_boolean	ft_isset(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (_true);
		i++;
	}
	return (_false);
}

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
			if (ft_isset(map[y][x], "NSEW0"))
			{
				if (!map[y][x + 1] || map[y][x + 1] == ' ')
					return (ft_putstr_fd("Error\n -> Invalid map.\n", 2), 1);
				if (map[y + 1] == NULL || !map[y + 1][x]
					|| map[y + 1][x] == ' ')
					return (ft_putstr_fd("Error\n -> Invalid map.\n", 2), 1);
				if ((x && (!map[y][x - 1] || map[y][x - 1] == ' ')) || !x)
					return (ft_putstr_fd("Error\n -> Invalid map.\n", 2), 1);
				if ((y && (map[y - 1] == NULL || !map[y - 1][x] \
					|| map[y - 1][x] == ' ')) || !y)
					return (ft_putstr_fd("Error\n -> Invalid map.\n", 2), 1);
			}
		}
	}
	return (_false);
}
