/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:59:50 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 10:18:22 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "cub3d.h"

t_boolean	key_is_color(char *key)
{
	if (ft_str_equals(key, "F") || ft_str_equals(key, "C"))
		return (_true);
	return (_false);
}

static t_boolean	str_is_numeric(char *value)
{
	size_t	index;

	index = 0;
	while (value[index])
	{
		if (!ft_is_digit(value[index]))
			return (_false);
		index++;
	}
	return (_true);
}

t_boolean	color_value_is_valid(char *value)
{
	char	**colors;
	int		tab_index;
	int		v;

	colors = ft_split(value, ',');
	if (!colors)
		return (_false);
	if (ft_str_tab_len(colors) != 3)
		return (ft_free_split(colors), _false);
	tab_index = 0;
	while (colors[tab_index] && tab_index < 3)
	{
		if (!str_is_numeric(colors[tab_index]))
			return (ft_free_split(colors), _false);
		if (ft_strlen(colors[tab_index]) > 3)
			return (ft_free_split(colors), _false);
		v = ft_atoi(colors[tab_index]);
		if (v < 0 || v > 255)
			return (ft_free_split(colors), _false);
		tab_index++;
	}
	return (ft_free_split(colors), _true);
}

static int	load_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	load_color(t_cub3d *cube, char *key, char *value)
{
	char	**colors;
	int		color;
	char	*tmp;

	colors = ft_split(value, ',');
	color = load_trgb(0, ft_atoi(colors[0]), \
		ft_atoi(colors[1]), ft_atoi(colors[2]));
	tmp = ft_strtrim(key, " 	\n");
	if (ft_str_equals(tmp, "F"))
		cube->floor_color = color;
	else if (ft_str_equals(tmp, "C"))
		cube->ceiling_color = color;
	ft_free_split(colors);
	free(tmp);
}
