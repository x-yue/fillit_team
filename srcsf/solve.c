/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:02:55 by ablin             #+#    #+#             */
/*   Updated: 2018/01/20 06:17:18 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** this function return the position of every hashtag of a tetriminos
*/

t_pos		ft_pos(char **board)
{
	int		col;
	int		line;
	int		count;
	t_pos	pos;

	line = 0;
	count = 0;
	while (board[line] != NULL && count != 4)
	{
		col = 0;
		while (board[line][col] != '\0')
		{
			if (board[line][col] == '#')
			{
				pos.x[count] = line;
				pos.y[count] = col;
				count++;
			}
			col++;
		}
		line++;
	}
	return (pos);
}

void		ft_tetripos(t_tetri *tetri, int size)
{
	t_tetri *tmp;

	tmp = tetri;
	if (tetri->x < size)
	{
		if (tetri->y == size - 1)
		{
			tetri->y = -1;
			tetri->x++;
		}
		tetri->y++;
	}
}

int			ft_checkpos(t_tetri *tetri, t_fit fit, char **map, int size)
{
	int		count;
	t_pos	pos;

	count = 0;
	pos = ft_pos(tetri->board);
//	printf("%d: {%d : %d}\n", size, fit.line + tetri->x + pos.x[count], fit.col + tetri->y + pos.y[count]);
	while (count < 4 && (fit.line + tetri->x + pos.x[count]) < size &&
	(fit.col + tetri->y + pos.y[count]) < size &&
	map[fit.line + tetri->x + pos.x[count]]
	[fit.col + tetri->y + pos.y[count]] == '.')//segfault here
	{
//		ft_putstr("xd2.0\n");
		count++;
	}
	if (count == 4)
		map = ft_insert(map, tetri, fit.line + tetri->x, fit.col + tetri->y);
	return (count);
}

int		ft_unfit(t_tetri *tetri, char **map, int size, t_fit fit)
{
	t_pos	pos;
	pos = ft_pos(tetri->board);
	if (tetri->prev == NULL && (tetri->x + fit.line + pos.x[0]) >= size - 1 && (tetri->y + fit.col + pos.y[0]) >= size - 1)
	{
		ft_putstr("\nincreasing\n");
		tetri->x = 0;
		tetri->y = -1;
		map = ft_map(map, size++);///
	}//elseif
	if (tetri->prev != NULL && (tetri->x + fit.line + pos.x[0]) >= size - 1 && (tetri->y + fit.col + pos.y[0]) >= size - 1)
	{
		tetri->x = 0;
		tetri->y = 0;
		tetri = tetri->prev;
		map = ft_erase(map, tetri->letter);//rmv map = if return size
	}
//	ft_putstr("xd4.0\n");
	ft_tetripos(tetri, size);
	ft_fit(tetri, ft_pos(tetri->board), size, map);
	return (size);//return map?
}

/*
** this function check if a tetriminos can fit
** calls to ft_set if it is the first time we call this ft
*/

char		**ft_fit(t_tetri *tetri, t_pos pos, int size, char **nmap)
{
	t_fit			fit;
	static	char	**map;

	//if (map == NULL)
	map = nmap;
	fit.line = 0;
	//ft_showtab(map);
//	ft_putchar('\n');
//	printf("%c: [%d : %d]\n",tetri->letter, tetri->x, tetri->y);
	while (map[fit.line] != NULL)
	{
		fit.col = 0;
		while (map[fit.line][fit.col] != '\n')
		{
	//	printf("(%d : %d | %c)\n", fit.line, fit.col, map[fit.line][fit.col]);
			if (map[fit.line + pos.x[0]][fit.col + pos.y[0]] == '.')
			{
				//ft_putstr("xd\n");
//					ft_showtab(map);
//					ft_putchar('\n');
				if ((ft_checkpos(tetri, fit, map, size)) == 4)
				{
					if (tetri->next != NULL)
						ft_fit(tetri->next, ft_pos(tetri->next->board), size, map);
					return (map);
				}
			//ft_putstr("xd3.0\n");
			}
			fit.col++;
		}
		fit.line++;
	}
	//	printf("(%d : %d)\n", fit.line, fit.col);
	size = ft_unfit(tetri, map, size, fit);
	return (map);
}
