/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:27:48 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/17 00:01:19 by yuxu             ###   ########.fr       */
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
	if (ft_read(av[1]) ==  0)
		return (0);
		//ft_putstr(ft_strdup("error\n"));
}
