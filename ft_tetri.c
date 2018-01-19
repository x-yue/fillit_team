/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:02:55 by ablin             #+#    #+#             */
/*   Updated: 2018/01/20 00:54:16 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_erase.c"
#include <stdio.h>

/*
** this function return the position of every hashtag of a tetriminos
*/

s_pos		ft_getpos(char **board)
{
	int		col;
	int		line;
	int		count;
	s_pos	pos;

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


t_tetri		*ft_tetripos(t_tetri *tetri, int size)
{
	char	letter;
	t_tetri *tmp;

	tmp = tetri;
	letter = tetri->letter;
	if (tetri->x < size)
	{
		if (tetri->y == size - 1)
		{
			tetri->y = -1;
			tetri->x++;
		}
		tetri->y++;
		/*
		while (tetri->letter != letter)
		{
			if (tetri->next != NULL)
				tetri = tetri->next;
			else
				tetri = tetri->start;
		}*/
	}
	return (tetri);
}

/*
** this function check if a tetriminos can fit
** calls to ft_set if it is the first time we call this ft
*/

char		**ft_fit(t_tetri *tetri, int size)
{
	int				line;
	int				col;
	int				count;
	static	int		placed;
	static	char	**map;
	s_pos	pos;

	if (map == NULL)
		placed = 0;
	if (map == NULL)
		map = ft_set(size);
	pos = ft_getpos(tetri->board);
	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while (map[line][col] != '\0')
		{
			if (map[line + pos.x[0]][col + pos.y[0]] == '.')
			{
			count = 0;
				while ((line + tetri->x + pos.x[count]) < size && (col + tetri->y + pos.y[count]) < size && map[line + tetri->x + pos.x[count]][col + tetri->y + pos.y[count]] == '.')
				{
					if (count == 3)
					{
						map = ft_insert(map, tetri, line + tetri->x, col + tetri->y, pos);
						placed++;
						if (tetri->next == NULL)
							return (map);
						tetri = tetri->next;
						ft_fit(tetri, size);
						return (map);
					}
					count++;
				}
			}
			col++;
		}
		line++;
	}
	if (tetri->prev == NULL && tetri->x == size - 1 && tetri->y == size - 1)
	{
		ft_putstr("\nincreasing\n");
		tetri->x = 0;
		tetri->y = 0;
		map = ft_map(map, size++);
	}
	if (tetri->prev != NULL && tetri->x == size - 1 && tetri->y == size - 1)
	{
		tetri->x = 0;
		tetri->y = 0;
		tetri = tetri->prev;
		map = ft_erase(map, tetri->letter);
	}
	ft_tetripos(tetri, size);
	ft_fit(tetri, size);
	return (map);
}
