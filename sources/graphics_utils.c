/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:09:26 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:42:28 by jbadaire         ###   ########.fr       */
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
	return (texture);
}

static t_loaded_textures load_textures(t_cub3d *cub3d)
{
	t_loaded_textures	textures;
	int					fd;
	char				*line;
	char				*key;
	char				*value;

	fd = open(cub3d->map.path, O_RDONLY);
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
	return (close(fd), free(line), textures);
}

static void destroy_texture(t_cub3d cub3d, t_texture texture)
{
	free(texture.key);
	free(texture.value);
	mlx_destroy_image(cub3d.mlx, texture.texture);
}

int	init_graphics_part(t_cub3d *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (-1);
	game->textures = load_textures(game);

	game->window = mlx_new_window(game->mlx, 128 * 10,128 *10, "Cub3d");
	mlx_loop(game->mlx);
	return (0);
}

void destroy_textures(t_cub3d cub3d, t_loaded_textures textures)
{
	destroy_texture(cub3d, textures.north);
	destroy_texture(cub3d, textures.south);
	destroy_texture(cub3d, textures.east);
	destroy_texture(cub3d, textures.west);
}