/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:06 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/24 17:35:34 by lunagda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string_utils.h>
#include "cub3d.h"
#include <stdlib.h>
#include "memory_utils.h"

char	**ft_copy_2d_array(char **src)
{
	size_t	length;
	size_t	index;
	char	**new_array;

	length = ft_str_tab_len(src);
	printf("length = %zu\n", length);
	index = 0;
	new_array = ft_calloc(length + 1, sizeof(char *));
	if (new_array == NULL)
		return (NULL);
	while (src[index])
	{
		new_array[index] = ft_strdup(src[index]);
		if (new_array[index] == NULL)
		{
			ft_free_split(new_array);
			return (NULL);
		}
		index++;
	}
	new_array[length] = NULL;
	return (new_array);
}
