/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 03:02:55 by ablin             #+#    #+#             */
/*   Updated: 2017/12/18 21:44:50 by ablin            ###   ########.fr       */
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
	ft_showtab(newmap);
	ft_putchar('\n');
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

/*
 * ft_getpos returns the pos of the hashtag requested (call)
 * called in ft_insert and ft_fit
*/

s_pos	ft_getpos(char **board, int call)
{
	s_pos	pos;
	int		line;
	int		col;
	int		count;

	line = 0;
	count = 0;
	
	pos.x = 0;//////
	pos.y = 0;//////
	while (board[line] != NULL)
	{
		col = 0;
		while (board[line][col] != '\0')
		{
			if (board[line][col] == '#')
				count++;
			if (count == call)
			{
				pos.x = line;
				pos.y = col;
				return (pos);
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

void	ft_insert(char **map, char **board, int line, int col)
{
	int		call;
	s_pos	pos;

	call = 2;
	map[line][col] = '#';
	while (call <= 4)
	{
		pos = ft_getpos(board, call);
		map[line + pos.x][col + pos.y] = '#'; //have to change the # by the corresponding letter
		call ++;
	}
	ft_putstr("map after insertion\n");
	ft_showtab(map);
}

/*
 * this function check if a tetriminos can fit
 * calls to ft_set if it is the first time we call this ft
 * calls to ft_map to expand the map if it cannot fit
 * calls to ft_insert if it fits
*/

int		ft_fit(char **board, int subcall)//need to make it shorter etc
{
	int				line;
	int				col;
	int				call;
	static int		size;
	static char		**map;
	s_pos	pos;
	
	if (subcall == 0)
	{
		map = ft_set();
		size = 2;
	}
	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while (map[line][col] != '\0')
		{
			call = 2;
			if (map[line][col] == '.')
			{
				pos = ft_getpos(board, call++);
				while ((line + pos.x) < size && (col + pos.y) < size &&  map[line + pos.x][col + pos.y] == '.')
				{
					if (call == 5)
					{
						ft_insert(map, board, line, col);
						return (1);
					}
					pos = ft_getpos(board, call++);
				}
			}
			col++;
		}
		line++;
	}
	map = ft_map(map, size++);
	ft_fit(board, ++subcall);
	return (0);
}
