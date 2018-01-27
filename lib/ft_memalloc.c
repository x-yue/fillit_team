/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:14:14 by ablin             #+#    #+#             */
/*   Updated: 2017/12/02 02:56:03 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (size));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size);
	return (str);
}
