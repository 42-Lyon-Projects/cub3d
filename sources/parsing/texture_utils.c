/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:47:25 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/07 11:24:32 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "string_utils.h"
#include <stdlib.h>

t_direction	get_texture_direction_from_string(char *key)
{
	if (ft_str_equals(key, "NO"))
		return (NORTH);
	if (ft_str_equals(key, "SO"))
		return (SOUTH);
	if (ft_str_equals(key, "WE"))
		return (WEST);
	if (ft_str_equals(key, "EA"))
		return (EAST);
	return (UNKNOWN);
}

t_loaded_textures	*get_texture_by_direction(t_cub3d *cub3d,
		t_direction direction)
{
	t_loaded_textures	*current_texture;

	current_texture = cub3d->textures;
	if (current_texture == NULL)
		return (NULL);
	while (current_texture != NULL)
	{
		if (current_texture->current_texture->direction == direction \
			&& current_texture->current_texture->texture != NULL)
			return (current_texture);
		current_texture = current_texture->next;
	}
	return (NULL);
}

static void	destroy_texture(t_cub3d *cub3d, t_texture *texture)
{
	if (texture != NULL)
	{
		if (texture->texture != NULL)
			mlx_destroy_image(cub3d->mlx, texture->texture);
		free(texture->key);
		free(texture);
	}
}

void	destroy_textures(t_cub3d *cub3d)
{
	t_loaded_textures	*tmp;
	t_loaded_textures	*next;

	tmp = cub3d->textures;
	while (tmp != NULL)
	{
		destroy_texture(cub3d, tmp->current_texture);
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
