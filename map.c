/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 00:39:57 by ablin             #+#    #+#             */
/*   Updated: 2018/01/20 05:24:03 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** sets the first map as small as a tetriminos can be (2*2)
** called once in ft_fit if it's the first time we call the ft
*/

char	**ft_set(int size)
{
	char	**map;
	int		line;
	int		col;

	if ((map = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (0);
	line = 0;
	while (line < size)
	{
		col = 0;
		map[line] = ft_strnew(size + 1);
		while (col < size)
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
** ft_map expands an existing map by 1 ( +1 col and line) and free the old map
** called in ft_fit if the tetriminos couldnt fit
*/

char	**ft_map(char **map, int size)
{
	char	**newmap;
	int		line;
	int		col;

	if ((newmap = (char **)malloc(sizeof(char *) * (size + 2))) == NULL)
		return (0);
	line = 0;
	while (map[line] != NULL)
	{
		col = -1;
		newmap[line] = ft_strnew(size + 2);
		while (map[line][++col] != '\n')
			newmap[line][col] = map[line][col];
		newmap[line][col] = '.';
		newmap[line][col + 1] = '\n';
		newmap[line++][col + 2] = '\0';
	}
	col = -1;
	newmap[line] = ft_strnew(size + 1);
	while (col++ < size)
		newmap[line][col] = '.';
	newmap[line][col] = '\n';
	newmap[line][col + 1] = '\0';
	newmap[line + 1] = NULL;
	free(map);
	return (newmap);
}

/*
** insert the tetriminos (board) `in the map
** called in ft_fit
*/

char	**ft_insert(char **map, t_tetri *tetri, int line, int col)
{
	int		count;
	s_pos	pos;

	pos = ft_getpos(tetri->board);
	count = 0;
	while (count < 4)
	{
		map[line + pos.x[count]][col + pos.y[count]] = tetri->letter;
		count++;
	}
	return (map);
}

/*
** this function prints the final map
*/

void	ft_showtab(char **board)
{
	int i;
	int j;

	i = 0;
	while (board[i] != NULL)
	{
		j = 0;
		while (board[i][j] != '\0')
		{
			ft_putchar(board[i][j]);
			j++;
		}
		i++;
	}
}
