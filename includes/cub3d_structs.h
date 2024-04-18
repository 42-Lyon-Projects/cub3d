/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:36 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/15 16:07:34 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
	#define CUB3D_STRUCT_H
	#include "boolean.h"
	#include <stddef.h>

	typedef enum e_direction
	{
		NORTH,
		EAST,
		SOUTH,
		WEST,
		UNKNOWN
	} t_direction;

	typedef struct s_texture
	{
		char		*key;
		void		*texture;
		t_direction	direction;
	}	t_texture;

	typedef struct s_loaded_textures
	{
		t_texture					*current_texture;
		struct s_loaded_textures	*next;
		struct s_loaded_textures	*previous;
	}	t_loaded_textures;

	typedef struct s_location
	{
		double	x;
		double	y;
	} t_location;

	typedef struct s_player
	{
		t_location	location;
		t_direction	spawn_direction;
	} t_player;

	typedef struct s_map {
		char			*path;
		char			**map;
		long long		map_height;
		t_player		player;
		t_location		exit;
		t_boolean		is_valid;
	} t_map;

	typedef struct s_cub3d
	{
		char				**file_content;
		t_loaded_textures	*textures;
		int					floor_color;
		int					ceiling_color;

		t_map				map;
		void				*mlx;
		void				*window;
	}	t_cub3d;

#endif
