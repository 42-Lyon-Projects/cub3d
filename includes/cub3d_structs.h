/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:36 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:20:29 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
	#define CUB3D_STRUCT_H
	#include "boolean.h"

	typedef struct s_texture
	{
		char *key;
		char *value;
		void *texture;
		t_boolean is_set;
	}	t_texture;

	typedef struct s_loaded_textures
	{
		t_texture north;
		t_texture south;
		t_texture east;
		t_texture west;
	}	t_loaded_textures;

	typedef enum e_direction
	{
		NORTH = 0,
		EAST = 1,
		SOUTH = 2,
		WEST = 3
	} t_direction;

	typedef struct s_location
	{
		double x;
		double y;
	} t_location;

	typedef struct s_player
	{
		t_location location;
		t_direction spawn_direction;
	} t_player;

	typedef struct s_map {
		char *path;
		char **map;
		int width;
		int height;
		t_player player;
		t_location exit;
		t_boolean is_valid;
	} t_map;

	typedef struct s_cub3d
	{
		t_loaded_textures	textures;
		int					floor_color;
		int					ceiling_color;

		t_map				map;
		void				*mlx;
		void				*window;
	}	t_cub3d;

#endif
