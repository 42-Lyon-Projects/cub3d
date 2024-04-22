/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:49:13 by lunagda           #+#    #+#             */
/*   Updated: 2024/04/22 16:52:56 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_cub3d *data)
{
	free_and_exit(data);
	exit(0);
}

int	key_press(int key, t_cub3d *data)
{
	if (key == 53 && data)
		exit(0);
	return (0);
}

int	key_release(int key, t_cub3d *data)
{
	if (key == 53 && data)
		exit(0);
	return (0);
}