/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:30:32 by ablin             #+#    #+#             */
/*   Updated: 2017/12/02 20:24:33 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;
	unsigned char	cchar;

	i = 0;
	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	cchar = (unsigned char)c;
	while (i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == cchar)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
