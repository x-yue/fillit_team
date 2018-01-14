/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:27:18 by ablin             #+#    #+#             */
/*   Updated: 2018/01/14 01:51:50 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

typedef	struct	s_tetri
{
	char	**board;
	char		letter;
	struct	s_tetri	*next;
	struct	s_tetri	*start;
}				t_tetri;

typedef	struct	struct_poss
{
	int		x[4];
	int		y[4];
}			s_poss;

typedef	struct	file_list //can remove
{
	int		fd;
	int		rd;
	int		i;
	char	buf[21];
}				f_list;

typedef	struct	three_int_list
{
	int		i;
	int		j;
	int		k;
}				i_list;

typedef	struct	united_struct
{
	int		i;
	int		line;
	int		hashtag_count;
	int		mv_up;
	int		mv_l;
	char	**tmp;
	char	**tmp_line;
	int		n;
	int		k[4];
}				nb_list;

//ft_read ft
char	**ft_board(char *str);
int		ft_check(char *str);
int		ft_read(char *filename);
//ft_united ft
char	**malloc_it(void);
char	**ft_swap_up(char **board, int line, int i, int mv_up);
int		first_left(char **board);
char	**ft_left(char **board);
char	**ft_united(char **board);
//tetri.c ft
char	**ft_map(char **map, int size);
char	**ft_set(int size);
s_poss	ft_getpos(char **board, int call);
char	**ft_insert(char **map, t_tetri *tetri, int line, int col);
char	**ft_fit(t_tetri *tetri, int size);
#endif
