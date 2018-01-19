/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:05:09 by ablin             #+#    #+#             */
/*   Updated: 2018/01/16 23:53:25 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_tetri.c"
#include "ft_united.c"
#include "ft_minsize.c"
#include <stdio.h>

/*
 * this function turns the string sent by ft_read into a 2D board
*/

char	**ft_board(char *str)//possible struct for maximum shrinking
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
			board[line][col++] = str[i++];
			count--;
		}
		board[line][col] = '\0';
		line++;
	}
	board[4] = NULL;
	return (ft_united(board));
}

/*
 * this function checks the validity of the tetriminos while it's still in the form of a string
 * it checks : the hashtag number (hnb), if the hashtags are adjacent (count) and if the tetriminos only contains '\n' '#' and '.'
*/

int	ft_check(char *str)
{
	int		i;
	int		count;
	int		hnb;

	if (ft_strlen(str) != 21)
		return (0);
	i = 0;
	count = 0;
	hnb = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '.' && str[i] != '#' && str[i] != '\n'))
			return (0);
		if (str[i] == '#' && hnb++ <= 5)
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
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n' || str[20] != '\n' || hnb != 4 || (count != 6 && count != 8))
		return (0);
	return (1);
}

/*
 * this function creates a new node which holds
 * -the letter of the tetriminos
 * -the tetriminos
 * -the first spot where we'll try to placed the tetriminos
 * -the previous node address
*/

y_list		*ft_lsttetri(y_list *lst, char **board, int tetrinb)
{
	t_tetri	*tetri;

	if ((tetri = (t_tetri*)malloc(sizeof(t_tetri))) == NULL)
		return (0);
	tetri->letter = 'A' + tetrinb;
	tetri->board = board;
	tetri->x = 0;
	tetri->y = 0;
	tetri->next = NULL;
	if (lst->tail == NULL)
	{
		tetri->prev = NULL;
		lst->head = tetri;
		lst->tail = tetri;
	}
	else
	{
		lst->tail->next = tetri;
		tetri->prev = lst->tail;
		lst->tail = tetri;
	}
	lst->length++;
	return (lst);
}

/*
 * this function prints the final map
*/

void	ft_showtab(char **arr)
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

/*
 * this function reads the file containing the tetriminos, sets the double chained list, calls to ft_check, then to ft_lsttetri and ft_board
 * ultimately, it calls to ft_fit
*/

int	ft_read(char *filename)
{
	f_struct	f;
	t_tetri		*tetri;
	y_list		*lst;

	if ((lst = (y_list*)malloc(sizeof(y_list))) == NULL)
		return (0);
	lst->length = 0;
	lst->tail = NULL;
	lst->head = NULL;
	f.tetrinb = 0;
	if ((f.fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((f.rd = read(f.fd, f.buf, 21)) == 21)
	{
		if (ft_check(f.buf) == 0)
			return (0);
		ft_lsttetri(lst, ft_board(f.buf), f.tetrinb++);
		tetri = lst->head;
	}
	if (f.rd != 20)
		return (0);
	ft_showtab(ft_fit(tetri, ft_minsize(f.tetrinb)));
	if (close(f.fd) == -1)
		return (0);
	return (1);
}
