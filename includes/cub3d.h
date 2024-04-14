/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:34:36 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:13:57 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
	#define CUB3D_H
	#include "cub3d_structs.h"
	#include "../minilibx-linux/mlx.h"

	int	init_graphics_part(t_cub3d *game);
	t_loaded_textures load_textures(t_cub3d *cub3d);
	t_cub3d *load_config(t_cub3d *cub3d);
	char	*get_line_key(char *line);
	char	*get_line_value(char *line);
	int	handle_file_error(char *argv[]);

#endif
