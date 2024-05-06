/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:18:05 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/06 14:41:47 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "string_utils.h"
#include <stdlib.h>

static t_boolean	map_characters_is_valid(char **map)
{
	int		line_index;
	int		char_index;

	line_index = 0;
	while (map[line_index] != NULL)
	{
		char_index = 0;
		while (map[line_index][char_index] != '\0')
		{
			if (map[line_index][char_index] != ' ' && \
				map[line_index][char_index] != '1' && \
				map[line_index][char_index] != '0' && \
				map[line_index][char_index] != 'N' && \
				map[line_index][char_index] != 'S' && \
				map[line_index][char_index] != 'E' && \
				map[line_index][char_index] != 'W')
				return (_false);
			char_index++;
		}
		line_index++;
	}
	return (_true);
}

static void	set_coordinates(t_cub3d *cub3d, int x, int y, t_direction direction)
{
	cub3d->map->player.location.x = x;
	cub3d->map->player.location.y = y;
	cub3d->map->player.spawn_direction = direction;
}

static void	load_player(t_cub3d *cub3d, char **map, int y)
{
	int			x;
	t_direction	direction;

	direction = UNKNOWN;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || \
				map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (direction == UNKNOWN)
					set_coordinates(cub3d, x, y, \
						direction = get_direction_from_string(&map[y][x]));
				else
					return (set_coordinates(cub3d, -1, -1, UNKNOWN));
			}
			x++;
		}
		y++;
	}
	if (direction == UNKNOWN)
		set_coordinates(cub3d, -1, -1, UNKNOWN);
}

t_boolean	map_is_valid(t_cub3d *cub3d)
{
	if (cub3d->map->map_height == -1)
		return (_false);
	if (!map_characters_is_valid(cub3d->map->map))
		return (_false);
	load_player(cub3d, cub3d->map->map, 0);
	if (cub3d->map->player.spawn_direction == UNKNOWN)
		return (_false);
	return (_true);
}

void	load_map(t_cub3d *cub3d, int value)
{
	char	*tmp;

	tmp = ft_strtrim(cub3d->file_content[value], " \n");
	while (tmp && ft_strlen(tmp) == 0)
	{
		free(tmp);
		tmp = ft_strtrim(cub3d->file_content[++value], " \n");
	}
	if (tmp)
		free(tmp);
	cub3d->map->map = ft_copy_2d_array(&cub3d->file_content[value]);
	if (cub3d->map->map == NULL)
		return (printf("Error\n -> Can't load map.\n"), free_and_exit(cub3d));
	cub3d->map->map_height = ft_str_tab_len(cub3d->map->map);
}
