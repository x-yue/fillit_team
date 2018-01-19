/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:27:48 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/14 01:36:42 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <sys/uio.h>
#include <sys/types.h>
#include "ft_read.c"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file");
		return (0);
	}
	if (ft_read(av[1]) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
}
