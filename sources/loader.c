/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 18:35:00 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:27:28 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"
#include "string_utils.h"

static t_texture	load_texture(void *mlx, char *key, char *value)
{
	int			img_width;
	int			img_height;
	t_texture	texture;

	texture.key = key;
	texture.value = value;
	texture.texture = mlx_xpm_file_to_image(mlx, value, &img_width, &img_height);
	texture.is_set = _true;
	return (texture);
}

t_loaded_textures load_textures(t_cub3d *cub3d, char *path)
{
	t_loaded_textures	textures;
	int					fd;
	char				*line;
	char				*key;
	char				*value;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		key = get_line_key(line);
		value = get_line_value(line);
		if (ft_str_equals(key, "NO"))
			textures.north = load_texture(cub3d->mlx, key, value);
		else if (ft_str_equals(key, "SO"))
			textures.south = load_texture(cub3d->mlx, key, value);
		else if (ft_str_equals(key, "WE"))
			textures.west = load_texture(cub3d->mlx, key, value);
		else if (ft_str_equals(key, "EA"))
			textures.east = load_texture(cub3d->mlx, key, value);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

t_cub3d *load_config(t_cub3d *cub3d)
{

}
