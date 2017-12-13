/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:27:48 by yuxu              #+#    #+#             */
/*   Updated: 2017/12/13 21:19:19 by yuxu             ###   ########.fr       */
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

char	***board_split(char **file)
{
	char		***boards;
	int			board_nb;
	int			line_all;
	int			line_board;
	int			i;

	line_all = 0;
	while (file[]


int		main(int ac, char **av)
{
	// open the test file 
//	int		fd;
//	void	*buf;
//	size_t	nbyte;
	char ***read_file;

//	nbyte = 1000;
	if (ac != 2)
	{
		//ft_putstr(ft_strdup("error\n"));
		ft_putstr("usage: fillit source_file");
		return (0);
	}

	// make a three dimention file to give tables with order
	//fd = open(av[1], O_RDONLY);
	//if (fd == -1)
	//	return (0);
	read_file = board_split(fd);
	if (ft_errors(read_file) == 0)
		ft_putstr(ft_strdup("error\n"));
}
