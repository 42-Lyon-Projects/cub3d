/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbadaire <jbadaire@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:22:36 by jbadaire          #+#    #+#             */
/*   Updated: 2024/04/14 19:22:38 by jbadaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_str_equals(const char *str1, const char *str2)
{
	size_t	index;

	if (!str1 || !str2)
		return (0);
	index = 0;
	while (str1[index] && str2[index])
	{
		if (str1[index] != str2[index])
			return (0);
		index++;
	}
	if (str1[index] != str2[index])
		return (0);
	return (1);
}