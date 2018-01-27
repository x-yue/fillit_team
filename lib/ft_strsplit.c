/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 21:41:19 by ablin             #+#    #+#             */
/*   Updated: 2017/12/04 23:04:55 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_nb_words(char const *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			nb++;
			while (s[i] != c && s[i] != '\0')
				i++;
			i--;
		}
		i++;
	}
	return (nb);
}

static int	ft_word_length(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nb_word;
	char	**split;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb_word = ft_nb_words(s, c);
	if ((split = (char **)malloc(sizeof(*split) * (nb_word + 1))) == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		split[i] = ft_strsub(s, 0, ft_word_length(s, c));
		if (split[i] == NULL)
			return (NULL);
		s = s + ft_word_length(s, c);
		i++;
	}
	split[i] = NULL;
	return (split);
}
