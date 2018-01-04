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
#include "libft.h"
#include <stdio.h>

void	ft_show1(char **arr)
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
	ft_show1(newmap);
	ft_putchar('\n');
	return (newmap);
}

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

s_pos	ft_getpos(char **board, int call)
{
	s_pos	pos;
	int		line;
	int		col;
	int		count;

	//printf("(%d)\n", call);
	line = 0;
	count = 0;
	
	pos.x = 0;//////
	pos.y = 0;//////
	while (board[line] != NULL)
	{
		col = 0;
		while (board[line][col] != '\0')
		{
			if (board[line][col] == '#')//can probably omit the first #
				count++;
			if (count == call)
			{
				pos.x = line;
				pos.y = col;
				//////printf("[%d : %d]\n", pos.x, pos.y);
				return (pos);
			}
			col++;
		}
		line++;
	}
	return (pos); //check if old pos and pos returned are the same, if it's the case, abort
}

void	ft_insert(char **map, char **board, int line, int col)
{
	int		call;
	s_pos	pos;

	call = 2;
	map[line][col] = '#';
	while (call <= 4)
	{
		pos = ft_getpos(board, call);
		map[line + pos.x][col + pos.y] = '#';
		call ++;
	}
	ft_putstr("\nmap after insertion\n");
	ft_show1(map);
}

int		ft_fit(char **map, char **board, int size)
{
	//free each line of the board then the board itself after copying the tetriminos
	//same for the map when expanding itself
	int		line;
	int		col;
	int		call;
	s_pos	pos;
	
	line = 0;
	while (map[line] != NULL)
	{
		col = 0;
		while (map[line][col] != '\0')
		{
			call = 2; //on check direct pour la pos du 2e hashtagd
			if (map[line][col] == '.')
			{
				pos = ft_getpos(board, call);
				call++;
				//printf("[%d : %d]", line, col);
				//printf("(%d : %d)\n", line + pos.x, col + pos.y);
				while ((line + pos.x) < size && (col + pos.y) < size &&  map[line + pos.x][col + pos.y] == '.' && call != 4)
				{
					pos = ft_getpos(board, call);
					call++;
				}
					pos = ft_getpos(board, call);
				if ((line + pos.x) < size && (col + pos.y) < size && map[line + pos.x][col + pos.y] == '.' && call == 4)
				{
				ft_insert(map, board, line, col);
					return (1);
				}
			}
			col++;
		}
		line++;
	}
	map = ft_map(map, size);
	ft_show1(map);
	size++;
	ft_fit(map, board, size);
	return (0);
}


void	ft_test2(char **board)
{
	ft_getpos(board, 1);///////////
	//si size = 2 infact col [2] = '\n'
	ft_getpos(board, 2);
	ft_getpos(board, 3);
	ft_getpos(board, 4);
}

void	ft_test(char **board)
{
	(void)board;
	char **map;

	map = ft_strsplit("####\n ####\n #..#\n ##..\n ", ' ');
	ft_putstr("original map\n");
	ft_show1(map);
	if (ft_fit(map, board, 4) == 0)
		ft_putstr("cant fit\n");
	return;



	/*
	map = ft_set();
	if (ft_fit(map, board, 2) == 0)
	{
		map = ft_map(map, 2);
		if (ft_fit(map, board, 3) == 0)
		{
			map = ft_map(map, 3);
			ft_fit(map, board, 4);
		}
	}*/
}
/*
int	main()
{
	return (0);
}*/
