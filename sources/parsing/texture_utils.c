/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:47:25 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/15 16:08:19 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../dependencies/libft/.includes/string_utils.h"
#include <stdlib.h>

t_direction	get_direction_from_string(char *key)
{
	if (ft_strncmp(key, "NO", 2) || ft_strncmp(key, "N", 1))
		return (NORTH);
	if (ft_strncmp(key, "SO", 2) || ft_strncmp(key, "S", 1))
		return (SOUTH);
	if (ft_strncmp(key, "WE", 2) || ft_strncmp(key, "W", 1))
		return (WEST);
	if (ft_strncmp(key, "EA", 2) || ft_strncmp(key, "E", 1))
		return (EAST);
	return (UNKNOWN);
}

t_loaded_textures	*get_texture_by_direction(t_cub3d *cub3d, t_direction direction)
{
	t_loaded_textures	*current_texture;

	current_texture = cub3d->textures;
	if (current_texture == NULL)
		return (NULL);
	while (current_texture != NULL)
	{
		if (current_texture->current_texture->direction == direction && current_texture->current_texture->texture != NULL)
			return (current_texture);
		if (current_texture->next != NULL)
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

