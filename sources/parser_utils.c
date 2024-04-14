/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:32:23 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 16:26:02 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../dependencies/libft/.includes/string_utils.h"
#include "../dependencies/libft/.includes/char_utils.h"
#include <stdio.h>
#include <stdlib.h>

char *get_line_key(char *line)
{
	char		*tmp;
	char		*key;
	int			first_space;

	tmp = ft_strtrim(line, " 	");
	if (!tmp)
		return (NULL);
	if (ft_strlen(tmp) == 0)
		return (free(tmp), NULL);
	first_space = ft_strchr(tmp, ' ') - tmp;
	key = ft_substr(tmp, 0, first_space);
	if (!key)
		return (free(tmp), NULL);
	return (free(tmp), key);
}

char *get_line_value(char *line)
{
	char		*tmp;
	char		*value;
	int			first_space;

	tmp = ft_strtrim(line, " 	");
	if (!tmp)
		return (NULL);
	if (ft_strlen(tmp) == 0)
		return (free(tmp), NULL);
	first_space = ft_strchr(tmp, ' ') - tmp;
	value = ft_substr(tmp, first_space, ft_strlen(tmp));
	if (!value)
		return (free(tmp), NULL);
	free(tmp);
	tmp = ft_strtrim(value, " 	");
	free(value);
	value = ft_strdup(tmp);
	return (free(tmp), value);
}

t_boolean key_is_texture(char *key)
{
	if (ft_strncmp(key, "NO", 2) == 0 || ft_strncmp(key, "SO", 2) == 0
		|| ft_strncmp(key, "WE", 2) == 0 || ft_strncmp(key, "EA", 2) == 0
		|| ft_strncmp(key, "S", 1) == 0)
		return (_true);
	return (_false);
}


t_boolean key_is_color(char *key)
{
	if (ft_strncmp(key, "F", 1) == 0 || ft_strncmp(key, "C", 1) == 0)
		return (_true);
	return (_false);
}

t_boolean color_value_is_valid(char *value)
{
	char	**colors;
	int		tab_index;
	int		index;

	colors = ft_split(value, ',');
	if (!colors)
		return (_false);
	if (ft_str_tab_len(colors) != 3)
		return (ft_free_split(colors), _false);
	tab_index = 0;
	index = 0;
	while (colors[tab_index] && tab_index < 3)
	{
		while (colors[tab_index][index] && index < 3)
		{
			if (!ft_is_digit(colors[tab_index][index]))
				return (ft_free_split(colors), _false);
			index++;
		}
		tab_index++;
	}
	return (ft_free_split(colors), _true);
}

