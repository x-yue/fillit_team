/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:22:15 by ablin             #+#    #+#             */
/*   Updated: 2017/11/21 20:22:16 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
