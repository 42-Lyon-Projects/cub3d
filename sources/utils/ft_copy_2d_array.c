/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:06 by jbadaire          #+#    #+#             */
/*   Updated: 2024/05/06 17:03:30 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string_utils.h>
#include "cub3d.h"
#include <stdlib.h>
#include "memory_utils.h"


static void fill(char *src, char *dest, size_t len)
{
	size_t index = 0;
	while(src[index])
	{
		if (src[index] == ' ')
			dest[index] = '/';
		else
			dest[index] = src[index];
		index++;
	}
	while (index < len)
	{
		dest[index] = '/';
		index++;
	}
}

size_t get_biggest_line(char **src)
{
	size_t len;
	size_t index;

	len = 0;
	index = 0;
	while (src[index])
	{
		if (ft_strlen(src[index]) > len)
			len = ft_strlen(src[index]);
		index++;
	}
	return len;
}

char	**ft_round_2d(char **src, int biggest_line)
{
	size_t	length;
	size_t	index;
	char	**new_array;

	length = ft_str_tab_len(src);
	index = 0;
	new_array = ft_calloc(length + 1, sizeof(char *));
	if (new_array == NULL)
		return (NULL);
	while (src[index])
	{

		new_array[index] = ft_calloc(biggest_line + 1, sizeof(char));
		fill(src[index], new_array[index], biggest_line);
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


char	**ft_copy_2d_array(char **src)
{
	size_t	length;
	size_t	index;
	char	**new_array;

	length = ft_str_tab_len(src);
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