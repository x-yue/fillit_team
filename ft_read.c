/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:05:09 by ablin             #+#    #+#             */
/*   Updated: 2018/01/14 03:41:06 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_tetri.c"
#include "ft_united.c"
#include "ft_minsize.c"
#include <stdio.h>

char	**ft_board(char *str)
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
	return (ft_united(board));
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

//t_tetri		*ft_pushbacktetri(t_tetri *tetri, char **board, int tetrinb)
//{
//	}

t_tetri		*ft_lsttetri(t_tetri *tetri, char **board, int tetrinb)
{
	t_tetri	*new;
	t_tetri	*tmp;

	if (tetrinb == 0)
	{
		tetri = NULL;
		if ((tetri = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
			return (0);
		tetri->letter = 'A';
		tetri->start = tetri; //////////////
		tetri->board = board;
		tetri->x = 0;
		tetri->y = 0;
		tetri->next = NULL;
		
	}
	if (tetrinb != 0)
	{
		tmp = tetri;
		if ((new = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
			return (0);
		new->letter = 'A' + tetrinb;
		new->start = tetri->start;
		new->board = board;
		new->x = 0;
		new->y = 0;
		new->next = NULL;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (tetri);
}

void	ft_test(t_tetri	*tetri)
{
	int		i;

	i = 0;
	while (i < 15)
	{
		ft_putchar(tetri->letter);
		ft_putchar('\n');
		ft_showtab(tetri->board);
		ft_putchar('\n');
		if (tetri->next == NULL)
		{
			tetri = tetri->start;
			ft_putchar(tetri->letter);
			ft_putchar('\n');
			ft_showtab(tetri->board);
			ft_putchar('\n');
			i++;
		}
		tetri->letter = tetri->letter + 1;
		tetri = tetri->next;
		i++;
	}
}

int	ft_read(char *filename)
{
	int		fd;
	int		rd;
	int		tetrinb;
	char	buf[21];
	char	**board;
	t_tetri		*tetri;

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
		if ((board = ft_board(buf)) == 0)
			return (0);
		tetri = ft_lsttetri(tetri, board, tetrinb);
		//calls to a ft which initialize then insert each board in the list
		tetrinb++;
	}
	//ft_test(tetri);
	ft_showtab(ft_fit(tetri, ft_minsize(2)));// call to showtab here
	//if (rd == -1 || rd > BUF_SIZE)
	//	return (0);
	if (close(fd) == -1)
		return (0);
	return (1);
}
