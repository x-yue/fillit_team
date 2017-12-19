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

char	**ft_set_map(char **map, char **board, int line)
{
	int		i;
	int		j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < line)
		{
			map[i][j] = board[i][j];
			j++;
		}
		map[i][j] = '\n';
		map[i][j + 1] = '\0';
		i++;
	}
	map[i] = NULL;
	ft_show1(map);
	return (map);
}

char	**ft_first_map(int line, int col, char **board)
{
	char	**map;
	int		i;

	i = 0;
	if (line < col)
		line = col;
	if ((map = (char **)malloc(sizeof(char *) * (line + 1))) == NULL)
		return (0);
	while (i < line)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * (line + 1))) == NULL)
			return (0);
		i++;
	}
	map = ft_set_map(map, board, line);
	return (map);
}

int		ft_first_tetri(char **board)
{
	tetri_struct	tetri;

	tetri.i = 0;
	tetri.column = 0;
	tetri.total = 0;
	while (board[tetri.i] != NULL && tetri.total != 4)
	{
		tetri.count = 0;
		tetri.j = 0;
		while (board[tetri.i][tetri.j] != '\0')
		{
			if (board[tetri.i][tetri.j] == '#')
			{
				board[tetri.i][tetri.j] = 'A';
				tetri.count = tetri.j + 1;
				tetri.total++;
			}
			tetri.j++;
		}
		if (tetri.column < tetri.count)
			tetri.column = tetri.count;
		tetri.i++;
	}
	ft_first_map(tetri.i, tetri.column, board);
	return (1);
}
/*
int	main()
{
	ft_first_tetri(ft_strsplit(".#..\n ###.\n ....\n ....\n ", ' '));
	return (0);
}*/
