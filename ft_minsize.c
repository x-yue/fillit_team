/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:02:57 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/14 01:43:17 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_minsize(int tetrinb)
{
	int	hashnb;
	int size;

	size = 2;
	hashnb = tetrinb * 4;
	if (hashnb <= 0)
		return (0);
	while (size * size <= hashnb)
	{
		size++;
		if (size * size >= hashnb)
			return (size);
	}
	return (0);
}
// if return 0 === no # ==> error
