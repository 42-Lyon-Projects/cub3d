/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:09:26 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/24 17:14:48 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "string_utils.h"
#include "cub3d.h"

static t_texture	*load_texture(void *mlx, char *key, char *value)
{
	int			w;
	int			h;
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	if (!texture)
		return (NULL);
	texture->key = ft_strdup(key);
	texture->texture = mlx_xpm_file_to_image(mlx, value, &w, &h);
	texture->direction = get_texture_direction_from_string(key);
	return (texture);
}

static void	add_texture(t_loaded_textures **textures, t_texture *texture)
{
	t_loaded_textures	*current_texture;
	t_loaded_textures	*next;

	if (!texture)
		return ;
	current_texture = *textures;
	while (*textures != NULL && current_texture->next != NULL)
		current_texture = current_texture->next;
	next = malloc(sizeof(t_loaded_textures));
	if (!next)
		return ;
	next->current_texture = texture;
	next->next = NULL;
	next->previous = current_texture;
	if (*textures == NULL)
		*textures = next;
	else
		current_texture->next = next;
}

static int	load_graphics_properties(t_cub3d *cub3d, int index, int limiter)
{
	char		*line;
	char		*key;
	char		*value;

	while (limiter < 6)
	{
		line = cub3d->file_content[index++];
		if (!line)
			break ;
		key = get_line_key(line);
		value = get_line_value(line);
		if (!key || !value)
			continue ;
		if (get_texture_direction_from_string(key) != UNKNOWN && \
			ft_endwith(value, ".xpm") && ++limiter)
			add_texture(&cub3d->textures, load_texture(cub3d->mlx, key, value));
		else if (key_is_color(key) && color_value_is_valid(value) && ++limiter)
			load_color(cub3d, key, value);
		free(key);
		free(value);
		if (textures_has_correctly_loaded(cub3d) && \
			cub3d->ceiling_color != -1 && cub3d->floor_color != -1)
			return (index);
	}
	if (limiter != 6 || !textures_has_correctly_loaded(cub3d) || \
		cub3d->ceiling_color == -1 || cub3d->floor_color == -1)
		return (printf("Error \n -> Textures error \n"), free_and_exit(cub3d), -1);
}

int	init_graphics_part(t_cub3d *cub3d)
{
	int	index;

	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (-1);
	cub3d->textures = NULL;
	cub3d->ceiling_color = -1;
	cub3d->floor_color = -1;
	index = load_graphics_properties(cub3d, 0, 0);
	if (index == -1)
		return (free_and_exit(cub3d), -1);
	return (index);
}
