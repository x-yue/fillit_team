/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:05:09 by ablin             #+#    #+#             */
/*   Updated: 2017/12/12 09:20:11 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

#define BUF_SIZE 1024
// may be bad for optimization but looks good
void	ft_show(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != '\0')
	{
		ft_putstr(arr[i]);
		i++;
	}
}

void	ft_cutstring(char *str)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			ft_show(ft_strsplit(ft_strsub(str, (unsigned int)start, (size_t)(i - start)), '\n'));
			start = i + 1;
		}
		i++;
	}
}

char	*ft_newstring(int size, char *filename)
{
	int		fd;
	int		rd;
	int		i;
	char	buf[BUF_SIZE + 1];
	char	*str;

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
		return (0);
	while ((rd = read(fd, buf, 1)) != 0)		//read returns -1 if it fails, maybe implement it
	{
		str[i] = *buf;
		i++;
	}
	i = 0;
	ft_cutstring(str);
	if (close(fd) == -1)
		return (0);
	return (str);
}

int		ft_read(char *filename)
{
	int		fd;
	int		rd;
	int		i;
	char	buf[BUF_SIZE + 1];

	i = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	rd = read(fd, buf, BUF_SIZE);	//read returns -1 if it fails, maybe implement it
	if (close(fd) == -1)
		return (0);
	if ((ft_newstring(fd, filename)) == 0)
		return (0);
	return (1);
}


int main(int ac, char **av)
{
	(void)ac;
	ft_read(av[1]);
	return (0);
}
