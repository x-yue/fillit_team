/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:22:36 by ablin             #+#    #+#             */
/*   Updated: 2017/12/02 21:06:45 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	j;
	char	*dup;

	i = 0;
	j = 0;
	dup = ft_strndup((char *)haystack, len);
	if (ft_strcmp(needle, "") == 0)
		return ((char *)haystack);
	while (dup[i] != '\0')
	{
		j = 0;
		while (dup[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return (&((char *)haystack)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
