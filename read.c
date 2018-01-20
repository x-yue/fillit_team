/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:05:09 by ablin             #+#    #+#             */
/*   Updated: 2018/01/20 06:18:15 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** this function turns the string sent by ft_read into a 2D board
*/

char		**ft_board(char *str)
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
** this function checks the validity of the tetriminos while it's still
** in the form of a string
** it checks : the hashtag number (hnb), if the hashtags are adjacent (count)
** and if the tetriminos only contains '\n' '#' and '.'
*/

int			ft_check(char *str)
{
	int		arr[3];

	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	while (str[arr[0]] != '\0')
	{
		if ((str[arr[0]] != '.' && str[arr[0]] != '#' && str[arr[0]] != '\n'))
			return (0);
		if (str[arr[0]] == '#' && arr[1]++ <= 5)
		{
			if (arr[0] <= 15 && str[arr[0] + 5] == '#')
				arr[2]++;
			if (arr[0] >= 5 && str[arr[0] - 5] == '#')
				arr[2]++;
			if (arr[0] <= 18 && str[arr[0] + 1] == '#')
				arr[2]++;
			if (arr[0] >= 1 && str[arr[0] - 1] == '#')
				arr[2]++;
		}
		arr[0]++;
	}
	if (arr[1] != 4 || (arr[2] != 6 && arr[2] != 8))
		return (0);
	return (1);
}

/*
** this function creates a new node which holds
** -the letter of the tetriminos
** -the tetriminos
** -the first spot where we'll try to placed the tetriminos
** -the previous node address
*/

t_double	*ft_lsttetri(t_double *lst, char **board, int tetrinb)
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
	return (lst);
}

/*
** this ft returns the minimum size of the map taking the nb of tetriminos
*/

int			ft_minsize(int tetrinb)
{
	int	hashnb;
	int size;

	size = 2;
	hashnb = tetrinb * 4;
	if (hashnb <= 0)
		return (0);
	while (size * size <= hashnb)
	{
		size++;
		if (size * size >= hashnb)
			return (size);
	}
	return (0);
}

/*
** this function reads the file containing the tetriminos,
** sets the double chained list, calls to ft_check,
** then to ft_lsttetri and ft_board
** ultimately, it calls to ft_fit
*/

int			ft_read(char *filename)
{
	t_file		f;
	t_tetri		*tetri;
	t_double	*lst;

	if ((lst = (t_double*)malloc(sizeof(t_double))) == NULL)
		return (0);
	lst->tail = NULL;
	lst->head = NULL;
	f.tetrinb = 0;
	f.end = 0;
	if ((f.fd = open(filename, O_RDONLY)) == -1)
		return (0);
	while ((f.rd = read(f.fd, f.buf, 21)) >= 20)
	{
		if (ft_check(f.buf) == 0)
			return (0);
		ft_lsttetri(lst, ft_board(f.buf), f.tetrinb++);
		tetri = lst->head;
		if (f.rd == 20)
			f.end = 1;
	}
	free(lst);
	if (close(f.fd) == -1 || f.end != 1)
		return (0);
	ft_showtab(ft_fit(tetri, ft_pos(tetri->board), ft_minsize(f.tetrinb)));
	return (1);
}
