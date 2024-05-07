/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:35 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/07 10:17:35 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <string_utils.h>
#include "cub3d.h"

static void	move_north(t_cub3d *cub3d, t_flood **flood, \
	t_flood *temp, char **map)
{
	size_t	y;
	size_t	x;

	y = temp->y;
	x = temp->x;
	if (y > 0 && map[y])
	{
		if (strlen(map[y]) >= x)
		{
			if (y && !set_contains_char(map[y - 1][x], "+/"))
			{
				y--;
				map[y][x] = '+';
				if (add_to_flood(flood, y, x))
					return (free_flood(flood), free_and_exit(cub3d));
			}
		}
	}
}

static void	move_south(t_cub3d *cub3d, t_flood **flood, \
	t_flood *temp, char **map)
{
	size_t	y;
	size_t	x;

	y = temp->y;
	x = temp->x;
	if (ft_str_tab_len(map) >= y + 1 && ft_strlen(map[y]) > x)
	{
		if (map[y + 1] && ft_strlen(map[y + 1]) > x && map[y + 1][x])
		{
			if (!set_contains_char(map[y + 1][x], "+/"))
			{
				y++;
				map[y][x] = '+';
				if (add_to_flood(flood, y, x))
					return (free_flood(flood), free_and_exit(cub3d));
			}
		}
	}
}

static void	move_east(t_cub3d *cub3d, t_flood **flood, \
	t_flood *temp, char **map)
{
	size_t	y;
	size_t	x;

	y = temp->y;
	x = temp->x;
	if (ft_str_tab_len(map) >= y && ft_strlen(map[y]) >= x)
	{
		if (map[y][x + 1] && !set_contains_char(map[y][x + 1], "+/"))
		{
			x++;
			map[y][x] = '+';
			if (add_to_flood(flood, y, x))
				return (free_flood(flood), free_and_exit(cub3d));
		}
	}
}

static void	move_west(t_cub3d *cub3d, t_flood **flood, \
	t_flood *temp, char **map)
{
	size_t	y;
	size_t	x;

	y = temp->y;
	x = temp->x;
	if (ft_str_tab_len(map) >= y && ft_strlen(map[y]) >= x && x > 0)
	{
		if (x && !set_contains_char(map[y][x - 1], "+/"))
		{
			x--;
			map[y][x] = '+';
			if (add_to_flood(flood, y, x))
				return (free_flood(flood), free_and_exit(cub3d));
		}
	}
}

void	floodfill(t_cub3d *cub3d, char **map)
{
	t_flood	*flood;
	t_flood	*new_flood;
	t_flood	*temp;

	flood = NULL;
	first_position(cub3d, &flood);
	while (flood)
	{
		temp = flood;
		new_flood = NULL;
		while (temp)
		{
			move_east(cub3d, &new_flood, temp, map);
			move_south(cub3d, &new_flood, temp, map);
			move_west(cub3d, &new_flood, temp, map);
			move_north(cub3d, &new_flood, temp, map);
			temp = temp->next;
		}
		free_flood(&flood);
		flood = new_flood;
	}
}
