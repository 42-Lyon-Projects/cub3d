/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_2d_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:42:15 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/18 15:23:06 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string_utils.h>

#include "cub3d.h"
#include <stdlib.h>
#include "memory_utils.h"

char	**ft_add_to_2d_array(char **twod_array, char *line)
{
	size_t	index;
	char	**new_array;

	if (twod_array == NULL)
	{
		new_array = ft_calloc(2, sizeof(char *));
		if (new_array == NULL)
			return (NULL);
		new_array[0] = line;
		return (new_array);
	}
	index = ft_str_tab_len(twod_array);
	new_array = ft_calloc(index + 2, sizeof(char *));
	if (new_array == NULL)
		return (NULL);
	index = 0;
	while (twod_array[index])
	{
		new_array[index] = twod_array[index];
		index++;
	}
	new_array[index] = line;
	return (new_array);
}
