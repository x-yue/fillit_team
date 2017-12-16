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

int		ft_errors(char ***board);
//1. open the file of test
//2. read the file of test
//3. check errors
//4. locate
//5. backtrack

int		main(int ac, char **av)
{
	char ***read_file;

	if (ac != 2)
	{
		ft_putstr("usage: fillit source_file");
		return (0);
	}
	if (ft_errors(read_file) == 0)
		ft_putstr(ft_strdup("error\n"));
}
