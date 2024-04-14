/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:09:26 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:12:44 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
