/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:18:05 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 16:15:47 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <stdlib.h>
#include "string_utils.h"


static t_boolean is_valid(char **map, int x, int y, char *allowed)
{
	t_boolean negative;
	t_boolean exists;
	char *is_allowed;

	negative = x < 0 || y < 0;
	exists = map[y] && map[y][x];
	is_allowed = ft_strchr(allowed, map[y][x]);
	return (!negative && exists && is_allowed != NULL);
}

char **ft_floodfill(char **map, char *allowed, char replacer, t_location start_at)
{
	int	x;
	int	y;
	int	amount;

	x = (int) start_at.x;
	y = (int) start_at.y;
	amount = 100;

	while (amount)
	{
		if (is_valid(map, (int) start_at.x + 1, (int) start_at.y, allowed))
		{
			x++;
			map[y][x] = replacer;
		}
		else if (is_valid(map, (int) start_at.x - 1, (int) start_at.y, allowed))
		{
			x--;
			map[y][x] = replacer;
		}
		else if (is_valid(map, (int) start_at.x, (int) start_at.y + 1, allowed))
		{
			y++;
			map[y][x] = replacer;
		}
		else if (is_valid(map, (int) start_at.x, (int) start_at.y - 1, allowed))
		{
			y--;
			map[y][x] = replacer;
		}
		amount--;
	}
	return (map);
}