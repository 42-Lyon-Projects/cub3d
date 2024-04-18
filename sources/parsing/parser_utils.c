/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:32:23 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 17:18:38 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../dependencies/libft/.includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

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

static size_t get_map_height(t_cub3d *cub3d)
{
	int		fd;
	size_t	len;
	char	*line;

	fd = open(cub3d->map.path, O_RDONLY);
	if (fd == -1)
		return 0;

	line = get_next_line(fd);
	len = 0;
	while (line != NULL)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return len;
}

void	parse_map(t_cub3d *cub3d)
{
	int	index;
	char *line;
	char **map;
	char	*tmp;

	map = ft_calloc((get_map_height(cub3d) + 1), sizeof(char *));
	if (!map)
		return ;
	index = 0;
	line = get_next_line(cub3d->map.fd);
	while (line != NULL)
	{
		tmp = ft_strtrim(line, "\n");
		if (ft_strlen(tmp) != 0)
			map[index++] = tmp;
		else
			free(tmp);
		free(line);
		line = get_next_line(cub3d->map.fd);
	}
	return (close(cub3d->map.fd), cub3d->map.map = map, free(line));
}