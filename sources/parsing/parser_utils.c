/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:32:23 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/24 17:28:28 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
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

void	load_file_content(t_cub3d *cub3d)
{
	int		fd;
	char	*line;
	char	**content;
	char	**tmp;

	fd = open(cub3d->map->path, O_RDONLY);
	if (fd == -1)
		return ;
	content = ft_calloc(1, sizeof(char *));
	if (!content)
		return (close(fd), (void) \
			printf("Error\n -> Can't allocate memory.\n"));
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_add_to_2d_array(content, ft_strtrim(line, "\n"));
		free(content);
		content = tmp;
		free(line);
		line = get_next_line(fd);
	}
	cub3d->file_content = content;
}
