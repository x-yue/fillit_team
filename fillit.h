/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 08:27:18 by ablin             #+#    #+#             */
/*   Updated: 2017/12/18 22:04:59 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

#define BUF_SIZE 546 //look for optimization
typedef	struct	file_list
{
	int		fd;
	int		rd;
	int		i;
	char	buf[BUF_SIZE + 1];
}				f_list;

typedef	struct	three_int_list
{
	int		i;
	int		j;
	int		k;
}				i_list;

typedef	struct	first_tetri_struct
{
	int		i;
	int		j;
	int		count;
	int		total;
	int		column;
}				tetri_struct;

typedef	struct	position_struct
{
	int		o_line;
	int		o_col;
	int		line;
	int		col;
}				pos_struct;

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

int		ft_checksize(char *str);
int		ft_custring(char *str);
int		ft_newstring(int size, char *filename);
int		ft_read(char *filename);

#endif
