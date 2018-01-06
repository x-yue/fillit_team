/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:05:09 by ablin             #+#    #+#             */
/*   Updated: 2017/12/18 22:30:30 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "tetri.c"
#include "ft_united.c"
#include <stdio.h>

int	ft_board(char *str, int tetrinb)
{
	int		line;
	int		col;
	int		count;
	int		i;
	char	**board;

	if ((board = (char **)malloc(sizeof(char *) * (4 + 1))) == NULL)
		return (0);
	line = 0;
	i = 0;
	while (i < 20)
	{
		count = 4;
		col = 0;
		board[line] = ft_strnew(5);
		while (count >= 0)
		{
			board[line][col] = str[i];
			i++;
			col++;
			count--;
		}
		board[line][col] = '\0';
		line++;
	}
	board[4] = NULL;
	ft_showtab(board);
	ft_putchar('\n');
	ft_fit(ft_united(board), tetrinb);
	return (1); //////return 1, 0 is for testing for only one board
}

int	ft_check(char *str)
{
	int		i;
	int		count;

	if (ft_strlen(str) != 21)
		return (0);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '.' && str[i] != '#' && str[i] != '\n'))
			return (0);
	if (str[i] == '#')
	{
		if (i <= 15 && str[i + 5] == '#')
			count++;
		if (i >= 5 && str[i - 5] == '#')
			count++;
		if (i <= 18 && str[i + 1] == '#')
			count++;
		if (i >= 1 && str[i - 1] == '#')
			count++;
	}
		i++;
	}
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	return (1);
}

int	ft_read(char *filename)
{
	int		fd;
	int		rd;
	int		tetrinb;
	char	buf[21];

	tetrinb = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((rd = read(fd, buf, 21)) >= 20)
	{
		if (ft_check(buf) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		if (ft_board(buf, tetrinb) == 0)
			return (0);
		tetrinb++;
	}
	//if (rd == -1 || rd > BUF_SIZE)
	//	return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}
