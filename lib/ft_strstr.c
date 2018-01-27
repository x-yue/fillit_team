/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:22:36 by ablin             #+#    #+#             */
/*   Updated: 2017/12/02 05:49:00 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (&((char *)haystack)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
