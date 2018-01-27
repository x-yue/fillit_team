/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:19:55 by ablin             #+#    #+#             */
/*   Updated: 2017/12/05 04:43:31 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_forward(char const *s)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_backward(char const *s)
{
	int		end;

	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	if (end < 0)
		end = 0;
	return (end);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		end;
	char	*trim;

	if (!s)
		return (NULL);
	j = 0;
	end = ft_strlen(s) - 1;
	i = ft_forward(s);
	if (i == end)
		return (ft_strnew(0));
	end = ft_backward(s);
	trim = ft_strsub(s, i, (end - i + 1));
	return (trim);
}
