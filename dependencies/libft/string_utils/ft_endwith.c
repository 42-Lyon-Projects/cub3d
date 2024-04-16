/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endwith.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:36:46 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/16 10:36:52 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../.includes/string_utils.h"
#include "../.includes/boolean.h"
#include <stdio.h>

int	ft_endwith(char *src, char *pattern)
{
	int	pattern_size;
	int	src_size;

	if (!pattern || !src)
		return (_false);
	pattern_size = (int) ft_strlen(pattern);
	src_size = (int) ft_strlen(src);
	if (pattern_size > src_size)
		return (_false);
	--pattern_size;
	--src_size;
	while (src_size >= 0 && pattern_size >= 0)
	{
		if (pattern[pattern_size] != src[src_size])
			return (_false);
		pattern_size--;
		src_size--;
	}
	return (_true);
}