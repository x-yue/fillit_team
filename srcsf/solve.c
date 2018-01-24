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

int			ft_checkpos(t_tetri *tetri, char **map, int size)
{
	int		count;
	t_pos	pos;

	count = 0;
	pos = ft_pos(tetri->board);
	while (count < 4 && (tetri->x + pos.x[count]) < size &&
	(tetri->y + pos.y[count]) < size &&
	map[tetri->x + pos.x[count]][tetri->y + pos.y[count]] == '.')
		count++;
	if (count == 4)
		map = ft_insert(map, tetri, tetri->x, tetri->y);
	return (count);
}

int		ft_unfit(t_tetri *tetri, char **map, int size)
{
	t_pos pos;

	pos = ft_pos(tetri->board);
	if (tetri->prev == NULL)
	{
		ft_putstr("\nincreasing\n");
		tetri->x = 0;
		tetri->y = 0;
		ft_map(map, size++);
	}
	if (tetri->prev != NULL)
	{
		tetri->x = 0;
		tetri->y = 0;
		tetri = tetri->prev;
		ft_erase(map, tetri->letter);
		ft_tetripos(tetri, size);
	}
	ft_fit(tetri, ft_pos(tetri->board), size, map);
	return (size);
}

/*
** this function check if a tetriminos can fit
** calls to ft_set if it is the first time we call this ft
*/

char		**ft_fit(t_tetri *tetri, t_pos pos, int size, char **nmap)
{
	static	char	**map;

	map = nmap;
	while (tetri->x + pos.x[0] < size)
	{
		while (tetri->y + pos.y[0] < size)
		{
			if (map[tetri->x + pos.x[0]][tetri->y + pos.y[0]] == '.')
			{
				if ((ft_checkpos(tetri, map, size)) == 4)
				{
					if (tetri->next != NULL)
						ft_fit(tetri->next, ft_pos(tetri->next->board), size, map);
					return (map);
				}
			}
			tetri->y++;
		}
		tetri->x++;
		tetri->y = 0;
	}
	size = ft_unfit(tetri, map, size);
	return (map);
}
