/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:36 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/22 15:44:23 by lunagda          ###   ########.fr       */
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
		t_location	plane;
	} t_player;

	typedef struct s_map {
		char			*path;
		char			**map;
		long long		map_height;
		t_player		player;
		t_location		exit;
		t_boolean		is_valid;
	} t_map;

	typedef struct s_image
	{
		void	*img;
		int		*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
	}	t_image;

	typedef struct s_vec
	{
		double	x;
		double	y;
	}	t_vec;

	typedef	struct s_ray
	{
		double		camera_x;
		t_vec		ray_dir;
	}	t_ray;
	
	typedef	struct s_dda
	{
		t_vec		side_dist;
		t_vec		delta_dist;
		int			step_x;
		int			step_y;
		int			map_x;
		int			map_y;
		double		perp_wall_dist;
		int			side;
		int			hit;
		int			line_height;
		int			draw_start;
		int			draw_end;
	}	t_dda;

	typedef struct s_cub3d
	{
		char				**file_content;
		t_loaded_textures	*textures;
		int					floor_color;
		int					ceiling_color;

		t_map				map;
		void				*mlx;
		void				*window;
		double				res_x;
		double				res_y;
		t_image				img;
	}	t_cub3d;

#endif
