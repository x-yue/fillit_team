/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:05:09 by ablin             #+#    #+#             */
/*   Updated: 2017/12/14 09:32:55 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "fillit.h"
#include "ft_errors.c"
#include "../libft/ft_putstr.c"
#include "../libft/ft_putchar.c"
#include <stdio.h>

char	ft_checksize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
		if ((i % 21) == 20 && (str[i] != '\n' || str[i] != '\0') &&
				str[i - 1] != '\n')
			return (0);
	}
	return (1);
}

void	ft_show(char **arr)
{
	int i;
	int j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		printf("%d", i);
		while (arr[i][j] != '\0')
		{
			ft_putchar(arr[i][j]);
			j++;
		}
		i++;
	}
}

char	ft_cutstring(char *str)
{
	i_list	list;
	char	**board;

	if ((board = (char **)malloc(sizeof(char *) * (5 + 1))) == NULL)
		return (0);
	while (list.j <= 4)
	{
		if ((board[list.j] = (char*)malloc(sizeof(char) * (5 + 1))) == NULL) //moved to check if it was the pb
				return (0);
			list.j++;
	}
	board[5] = NULL;
	while (*str != '\0')
	{
		list.j = 0;
		while (list.j < 4 && *str != '\0')
		{
			//otherwise should be here
			list.k = 0;
			while (list.k <= 4 && *str != '\0')
			{
				board[list.j][list.k] = *str;
				str++;
				list.k++;
			}
			board[list.j][list.k] = '\0';
			list.j++;
		}
		board[4][0] = '\n';
		board[4][1] = '\0';
		str++;
		ft_errors(board);
	}
	return (1);
}

char	ft_newstring(int size, char *filename)
{
	f_list	list;
	char	*str;

	list.i = 0;
	if ((list.fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	while ((list.rd = read(list.fd, list.buf, 1)) != 0)
	{
		str[list.i] = *list.buf;
		list.i++;
	}
	str[list.i] = '\0';
	if (list.rd == -1)
		return (0);
	if (ft_checksize(str) == 0)
		return (0);
	ft_cutstring(str);
	if (close(list.fd) == -1)
		return (0);
	return (1);
}

char	ft_read(char *filename)
{
	f_list	list;

	if ((list.fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("error");
		return (0);
	}
	list.rd = read(list.fd, list.buf, BUF_SIZE);
	if (list.rd == -1)
	{
		ft_putstr("error");
		return (0);
	}
	if (close(list.fd) == -1)
	{
		ft_putstr("error");
		return (0);
	}
	if ((ft_newstring(list.rd, filename)) == 0)
	{
		ft_putstr("error");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	(void)ac;
	ft_read(av[1]);
	return (0);
}
