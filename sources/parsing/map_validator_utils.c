/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:17:29 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/07 10:17:29 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <stdlib.h>
#include "string_utils.h"

void	free_flood(t_flood **flood)
{
	t_flood	*temp;

	temp = *flood;
	if (!temp->next)
	{
		free(*flood);
		*flood = NULL;
		return ;
	}
	while (*flood)
	{
		temp = *flood;
		*flood = temp->next;
		free(temp);
	}
	*flood = NULL;
}

int	add_to_flood(t_flood **flood, size_t y, size_t x)
{
	t_flood	*new;
	t_flood	*temp;

	new = malloc(sizeof(*new));
	if (!new)
		return (1);
	new->y = y;
	new->x = x;
	new->next = NULL;
	if (!*flood)
		*flood = new;
	else
	{
		temp = *flood;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (0);
}

void	first_position(t_cub3d *cub3d, t_flood **flood)
{
	int	y;
	int	x;

	y = (int) cub3d->map->player.location.y;
	x = (int) cub3d->map->player.location.x;
	if (add_to_flood(flood, y, x))
		return (free_flood(flood), free_and_exit(cub3d));
}

t_boolean	set_contains_char(char c, char *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

int	map_is_one_block(t_cub3d *cub3d)
{
	char		**copy;
	size_t		index;
	size_t		index_2;
	t_boolean	is_valid;

	is_valid = _true;
	copy = ft_round_2d(cub3d->map->map, get_biggest_line(cub3d->map->map));
	if (!copy)
		return (ft_free_split(copy), 0);
	floodfill(cub3d, copy);
	index = 0;
	while (copy[index])
	{
		index_2 = 0;
		while (copy[index][index_2])
		{
			if (copy[index][index_2] != '+' && copy[index][index_2] != '/')
				is_valid = _false;
			index_2++;
		}
		index++;
	}
	if (is_valid)
		return (ft_free_split(copy), 1);
	return (ft_free_split(copy), 0);
}
