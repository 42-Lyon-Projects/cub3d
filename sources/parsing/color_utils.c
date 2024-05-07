/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 09:59:50 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/07 11:47:16 by jbadaire         ###   ########.fr       */
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
	char	*tmp;

	colors = ft_split(value, ',');
	if (!colors)
		return (_false);
	if (ft_str_tab_len(colors) != 3)
		return (ft_free_split(colors), _false);
	tab_index = 0;
	while (colors[tab_index] && tab_index < 3)
	{
		tmp = ft_strtrim(colors[tab_index], " 	");
		if (!str_is_numeric(tmp))
			return (free(tmp), ft_free_split(colors), _false);
		if (ft_strlen(tmp) > 3)
			return (free(tmp), ft_free_split(colors), _false);
		v = ft_atoi(tmp);
		if (v < 0 || v > 255)
			return (free(tmp), ft_free_split(colors), _false);
		tab_index++;
		free(tmp);
	}
	return (ft_free_split(colors), _true);
}

static int	load_trgb(char *st, char *sr, char *sg, char *sb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = ft_atoi(st);
	r = ft_atoi(sr);
	g = ft_atoi(sg);
	b = ft_atoi(sb);
	free(st);
	free(sr);
	free(sg);
	free(sb);
	return (t << 24 | r << 16 | g << 8 | b);
}

void	load_color(t_cub3d *cube, char *key, char *value)
{
	char	**colors;
	int		color;
	char	*tmp;

	colors = ft_split(value, ',');
	if (!colors)
		return ;
	if (ft_str_tab_len(colors) != 3)
		return (ft_free_split(colors));
	color = load_trgb(ft_strdup("0"), \
	ft_strtrim(colors[0], " 	"), \
		ft_strtrim(colors[1], " 	"), \
		ft_strtrim(colors[2], " 	"));
	tmp = ft_strtrim(key, " 	\n");
	if (ft_str_equals(tmp, "F"))
		cube->floor_color = color;
	else if (ft_str_equals(tmp, "C"))
		cube->ceiling_color = color;
	ft_free_split(colors);
	free(tmp);
}
