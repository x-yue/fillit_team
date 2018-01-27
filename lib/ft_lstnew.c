/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:46:28 by ablin             #+#    #+#             */
/*   Updated: 2017/12/04 23:09:06 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *nlist;

	nlist = (t_list*)malloc(sizeof(t_list));
	if (nlist == NULL)
		return (NULL);
	if ((nlist->content = (char *)malloc(sizeof(char) * content_size)) == NULL)
		return (NULL);
	if (content == NULL || (ft_strcmp(content, "") == 0))
	{
		nlist->content = NULL;
		nlist->content_size = 0;
	}
	else
	{
		ft_memcpy(nlist->content, content, content_size);
		nlist->content_size = content_size;
	}
	nlist->next = NULL;
	return (nlist);
}
