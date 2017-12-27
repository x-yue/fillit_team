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
#include <stdio.h>

void	ft_show(char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			ft_putchar(arr[i][j]);
			j++;
		}
		i++;
	}
}

int	ft_cutstring(char *str, int tetrinb)
{
	int		line;
	int		col;
	int		count;
	int		i;
	char	**board;

	(void)tetrinb;
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
	ft_show(board); //check return value and return 0 if wrong
	ft_putchar('\n'); //remove
	ft_map(board, 4);
	return (0);
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
	printf("[%d]\n", count);
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
		if (ft_check(buf) == 0 || ft_cutstring(buf, tetrinb) == 0)
			return (0);
		tetrinb++;
	}
	//if (rd == -1 || rd > BUF_SIZE)
	//	return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_read(av[1]);
	return (0);
}
