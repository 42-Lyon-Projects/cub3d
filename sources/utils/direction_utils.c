/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:42:56 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/18 13:42:56 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "string_utils.h"

t_direction	get_direction_from_string(char *key)
{
	if (ft_strncmp(key, "N", 1))
		return (NORTH);
	if (ft_strncmp(key, "S", 1))
		return (SOUTH);
	if (ft_strncmp(key, "W", 1))
		return (WEST);
	if (ft_strncmp(key, "E", 1))
		return (EAST);
	return (UNKNOWN);
}
