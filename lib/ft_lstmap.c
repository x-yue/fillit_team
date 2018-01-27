/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 00:38:57 by ablin             #+#    #+#             */
/*   Updated: 2017/12/04 19:37:49 by ablin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	tmp2 = tmp;
	while (lst->next && f)
	{
		tmp->next = f(lst->next);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (tmp2);
}
