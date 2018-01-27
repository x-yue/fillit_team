/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:02:55 by ablin             #+#    #+#             */
/*   Updated: 2018/01/27 01:05:28 by ablin            ###   ########.fr       */
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

/*
** this function check the position for the tetri, if the 4 spots are available
** we insert the tetri using ft_insert
*/

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

/*
** this ft calls to fit, if fits return 1, the tetriminos has been inserted
** else, we get to the previous tetri, try to place it...
*/

char		**ft_solve(t_tetri *tetri, char **map, int size, int tnb)
{
	t_pos	pos;

	pos = ft_pos(tetri->board);
	while (tnb != 0)
	{
		if (ft_fit(tetri, ft_pos(tetri->board), size, map) == 1 && tnb-- != 0)
			tetri = tetri->next;
		else
		{
			tetri->x = 0;
			tetri->y = 0;
			if (tetri->prev == NULL)
				map = ft_map(map, size++);
			if (tetri->prev != NULL)
			{
				tetri = tetri->prev;
				map = ft_erase(map, tetri->letter);
				tnb++;
			}
		}
	}
	return (map);
}

/*
** this function check for the first dot on the mao
** starting from the position at tetri->x / tetri->y pos
** calls to ft_checkpos to check if the tetriminos can fit / insert it
*/

int			ft_fit(t_tetri *tetri, t_pos pos, int size, char **nmap)
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
					tetri->y++;
					return (1);
				}
			}
			tetri->y++;
		}
		tetri->x++;
		tetri->y = 0;
	}
	return (2);
}
