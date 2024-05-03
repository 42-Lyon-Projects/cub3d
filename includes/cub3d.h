/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:36 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/02 13:55:34 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
	#define CUB3D_H
	#include "cub3d_structs.h"
	#include "stdio.h"
	#include "math.h"
	#include "../dependencies/minilibx-linux/mlx.h"

	#ifndef M_PI
	# define M_PI 3.14159265358979323846
	#endif
	#ifndef M_PI_2
	# define M_PI_2 (M_PI/2)
	#endif
	
	#define W 119
	#define A 97
	#define S 115
	#define D 100
	#define LEFT 65361
	#define RIGHT 65363
	#define ESC 65307

	#define ROTATE_SPEED 0.025
	#define MOVE_SPEED 0.025

	int					handle_file_error(char *argv[]);
	int					init_graphics_part(t_cub3d *game);
	void				destroy_textures(t_cub3d *cub3d);
	void				free_and_exit(t_cub3d *cub3d);
	t_loaded_textures	*get_texture_by_direction(t_cub3d *cub3d, t_direction direction);
	t_direction			get_texture_direction_from_string(char *key);
	t_direction			get_direction_from_string(char *key);
	t_boolean			textures_has_correctly_loaded(t_cub3d *cub3d);
	t_boolean			key_is_color(char *key);
	t_boolean			color_value_is_valid(char *value);
	void				load_color(t_cub3d *cube, char *key, char *value);
	char				*get_line_key(char *line);
	char				*get_line_value(char *line);
	t_boolean			map_is_valid(t_cub3d *cub3d);
	char				**ft_add_to_2d_array(char **twod_array, char *line);
	char				**ft_copy_2d_array(char **src);
	void				load_file_content(t_cub3d *cub3d);
	void				load_map(t_cub3d *cub3d, int value);
	int					ft_init(t_cub3d *data);
	void				dda_algo(t_cub3d *data, t_ray *ray, t_dda *dda);
	int					key_release(int key, t_cub3d *data);
	int					key_press(int key, t_cub3d *data);
	int					close_window(t_cub3d *data);
	int					raycasting(void *param);
	void				move_forward(t_cub3d *data);
	void				move_backward(t_cub3d *data);
	void				move_left(t_cub3d *data);
	void				move_right(t_cub3d *data);
	void				cam_rotate_left(t_cub3d *data);
	void				cam_rotate_right(t_cub3d *data);
	void				player_interaction(t_cub3d *data);
	void				get_wall_side(t_cub3d *data, t_dda *dda, t_ray *ray);
	void				texture_prep(t_cub3d *data, t_dda *dda, t_ray *ray);
	int					get_pixel_color(t_cub3d *data, int x, int y);
	t_boolean			map_is_open(char **map);

#endif
