/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 01:46:22 by yuxu              #+#    #+#             */
/*   Updated: 2018/01/14 02:16:52 by yuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"
#include "libft.h"

char	**ft_erase(char **map, char letter)
{
	int	line;
	int col;

	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while(map[line][col] != '\n')
		{
			if (map[line][col] == letter)
				map[line][col] = '.';
			col++;
		}
		line++;
	}
	return(map);
}

void	ft_showtab(char **board)
{
	int line;

	line = 0;
	while (board[line] != NULL)
	{
		ft_putstr(board[line]);
		line++;
	}
}

int		main(void)
{
	char letter;
	char **map;

	letter = 'S';
	map = ft_strsplit("sssNNS..\n .BB.SSS\n ..SS..\n .LJKFD....S\n", ' ');
	 ft_showtab(map);
	 ft_putchar('\n');
	 ft_showtab(ft_erase(map, letter));
	//printf("%s",ft_erase(map, letter));
	return 0;
}
