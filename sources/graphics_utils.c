/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:09:26 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 13:43:12 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "string_utils.h"

static t_texture *load_texture(void *mlx, char *key, char *value)
{
	int img_width;
	int img_height;
	t_texture *texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->key = ft_strdup(key);
	texture->texture = mlx_xpm_file_to_image(mlx, value, &img_width, &img_height);
	texture->direction = get_direction_from_string(key);
	return (texture);
}

static void add_texture(t_loaded_textures **textures, t_texture *texture)
{
	t_loaded_textures *current_texture;
	t_loaded_textures *next;

	current_texture = *textures;
	while (*textures != NULL && current_texture->next != NULL)
		current_texture = current_texture->next;

	next = malloc(sizeof(t_loaded_textures));
	if (!next)
		return;

	next->current_texture = texture;
	next->next = NULL;
	next->previous = current_texture;
	if (*textures == NULL)
		*textures = next;
	else
		current_texture->next = next;
}

static void load_textures(t_cub3d *cub3d, int index)
{
	char		*line;
	char		*key;
	char		*value;

	cub3d->map.fd = open(cub3d->map.path, O_RDONLY);
	if (cub3d->map.fd == -1)
		return (printf("Error\n -> Can't open file.\n"), free_and_exit(cub3d));
	line = get_next_line(cub3d->map.fd);
	while (line != NULL)
	{
		key = get_line_key(line);
		value = get_line_value(line);
		if (get_direction_from_string(key) != UNKNOWN && ft_strlen(key) != 0 && ft_endwith(value, ".xpm") && ++index)
			add_texture(&cub3d->textures, load_texture(cub3d->mlx, key, value));
		free(line);
		free(key);
		free(value);
		if (textures_has_correctly_loaded(cub3d))
			break;
		line = get_next_line(cub3d->map.fd);
	}
	if (index != 4 || !textures_has_correctly_loaded(cub3d))
		return (printf("Error \n -> Invalid texture\n"), close(cub3d->map.fd), free_and_exit(cub3d));
}
static void load_colors(t_cub3d *cub3d, int index)
{
	char		*line;
	char		*key;
	char		*value;

	line = get_next_line(cub3d->map.fd);
	while (line != NULL && (cub3d->ceiling_color == -1 || cub3d->floor_color == -1))
	{
		key = get_line_key(line);
		value = get_line_value(line);
		if (key_is_color(key) && color_value_is_valid(value) && ft_strlen(key) != 0 && ++index)
			load_color(cub3d, key, value);
		free(line);
		free(key);
		free(value);
		if (cub3d->ceiling_color != -1 && cub3d->floor_color != -1)
			break;
		line = get_next_line(cub3d->map.fd);
	}
	if (index != 2)
		return (printf("Error \n -> Invalid color key\n"), close(cub3d->map.fd), free_and_exit(cub3d));
	if (cub3d->ceiling_color == -1 || cub3d->floor_color == -1)
		return (printf("Error\n -> Invalid colors\n"), close(cub3d->map.fd), free_and_exit(cub3d));
}

int init_graphics_part(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->map.fd = -1;
	if (!cub3d->mlx)
		return (-1);
	cub3d->textures = NULL;
	printf("Loading textures...\n");
	load_textures(cub3d, 0);
	printf("Textures loaded\n");
	cub3d->ceiling_color = -1;
	cub3d->floor_color = -1;
	printf("Loading colors...\n");
	load_colors(cub3d, 0);
	printf("Colors loaded\n");


	//cub3d->window = mlx_new_window(cub3d->mlx, 128 * 10,128 *10, "Cub3d");
	//mlx_loop(cub3d->mlx);
	return (1);
}
