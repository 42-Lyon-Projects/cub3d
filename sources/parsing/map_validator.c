/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 08:45:57 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/06 17:02:50 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
#include <string_utils.h>
#include "cub3d.h"

static void move_north(t_cub3d *cub3d, t_flood **flood, t_flood *temp, char **map)
{
	size_t j;
	size_t i;

	j = temp->y;
	i = temp->x;
	if (j > 0 && map[j])
	{
		if (strlen(map[j]) >= i)
		{
			if (j && !set_contains_char(map[j - 1][i], "+/"))
			{
				j--;
				map[j][i] = '+';
				if (add_to_flood(flood, j, i))
					return (free_flood(flood), free_and_exit(cub3d));
			}
		}
	}
}

static void move_south(t_cub3d *cub3d, t_flood **flood, t_flood *temp, char **map)
{
	size_t y;
	size_t x;

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

static void move_east(t_cub3d *cub3d, t_flood **flood, t_flood *temp, char **map)
{
	size_t j;
	size_t i;

	j = temp->y;
	i = temp->x;
	if (ft_str_tab_len(map) >= j && ft_strlen(map[j]) >= i)
	{
		if (map[j][i + 1] && !set_contains_char(map[j][i + 1], "+/"))
		{
			i++;
			map[j][i] = '+';
			if (add_to_flood(flood, j, i))
				return (free_flood(flood), free_and_exit(cub3d));
		}
	}
}

static void move_west(t_cub3d *cub3d, t_flood **flood, t_flood *temp, char **map)
{
	size_t j;
	size_t i;

	j = temp->y;
	i = temp->x;
	if (ft_str_tab_len(map) >= j && ft_strlen(map[j]) >= i && i > 0)
	{
		if (i && !set_contains_char(map[j][i - 1], "+/"))
		{
			i--;
			map[j][i] = '+';
			if (add_to_flood(flood, j, i))
				return (free_flood(flood), free_and_exit(cub3d));
		}
	}
}

void floodfill(t_cub3d *cub3d, char **map)
{
	t_flood *flood;
	t_flood *new_flood;
	t_flood *temp;

	flood = NULL;
	first_position(cub3d, &flood, map);
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
