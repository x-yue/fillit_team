/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:02:55 by ablin             #+#    #+#             */
/*   Updated: 2018/01/14 01:37:22 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/* 
 * ft_map expands an existing map by 1 ( +1 col and line)
 * called in ft_fit if the tetriminos couldnt fit
*/

char	**ft_map(char **map, int size)//should free the old map
{
	char	**newmap;
	int		line;
	int		col;

	if ((newmap = (char **)malloc(sizeof(char *) * (size + 2))) == NULL)//size + 2 cause we send the size of the board w/o counting the \0
		return (0);
	line = 0;
	while (map[line] != NULL)
	{
		col = -1;
		newmap[line] = ft_strnew(size + 2);//see above why size + 2
		while (map[line][++col] != '\n')
			newmap[line][col] = map[line][col];
		newmap[line][col] = '.';
		newmap[line][col + 1] = '\n';
		newmap[line][col + 2] = '\0';
		line++;
	}
	col = -1;
	newmap[line] = ft_strnew(size + 1);
	while (col++ < size)
		newmap[line][col] = '.';
	newmap[line][col] = '\n';
	newmap[line][col + 1] = '\0';
	newmap[line + 1] = NULL;
	return (newmap);
}

/*
 * sets the first map as small as a tetriminos can be (2*2)
 * called once in ft_fit if it's the first time we call the ft
*/

char	**ft_set()
{
	char	**map;
	int		line;
	int		col;

	if ((map = (char **)malloc(sizeof(char *) * (2 + 1))) == NULL)
		return (0);
	line = 0;
	while (line < 2)
	{
		col = 0;
		map[line] = ft_strnew(3);
		while (col < 2)
		{
			map[line][col] = '.';
			col++;
		}
		map[line][col] = '\n';
		map[line][col + 1] = '\0';
		line++;
	}
	map[line] = NULL;
	return (map);
}

s_poss		ft_newpos(char **board)
{
	int		col;
	int		line;
	int		count;
	s_poss	pos;

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
 * insert the tetriminos (board)  in the map
 * called in ft_fit
*/

char	**ft_insert(char **map, t_tetri *tetri, int line, int col)
{
	int		count;
	s_poss	pos;

	pos = ft_newpos(tetri->board);
	count = 0;
	while (count < 4)
	{
		map[line + pos.x[count]][col + pos.y[count]] = tetri->letter;
		count++;
	}
	return (map);
}

/*
 * this function check if a tetriminos can fit
 * calls to ft_set if it is the first time we call this ft
*/

char		**ft_fit(t_tetri *tetri, int size)//need to make it shorter etc
{
	int				line;
	int				col;
	int				count;
	static	char	**map;
	s_poss	pos;

	if (map == NULL)
		map = ft_set();
	pos = ft_newpos(tetri->board);
	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while (map[line][col] != '\0')
		{
			count = 1;
			if (map[line][col] == '.')
			{
				while ((line + pos.x[count]) < size && (col + pos.y[count]) < size && map[line + pos.x[count]][col + pos.y[count]] == '.')
				{
					if (count == 4)
					{
						map = ft_insert(map, tetri, line, col);
						if (tetri->next != NULL)
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
	if (tetri->next == NULL)
		return (map);
	map = ft_map(map, size++);
	ft_fit(tetri, size);
	return (map);
}
