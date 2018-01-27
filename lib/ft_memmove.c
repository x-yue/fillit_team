/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:16:41 by ablin             #+#    #+#             */
/*   Updated: 2017/12/03 00:10:54 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (dst > src)
	{
		while (len > i)
		{
			len--;
			str1[len] = str2[len];
		}
	}
	else
	{
		while (i < len)
		{
			str1[i] = str2[i];
			i++;
		}
	}
	return (str1);
}
