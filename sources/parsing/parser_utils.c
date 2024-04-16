/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:32:23 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/15 17:15:05 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../dependencies/libft/.includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*get_line_key(char	*line)
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
	free(tmp);
	tmp = ft_strtrim(key, " 	\n");
	return (free(key), tmp);
}

char	*get_line_value(char *line)
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
	value = ft_strtrim(tmp, " \n");
	return (free(tmp), value);
}