/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdiakit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:13:24 by abdiakit          #+#    #+#             */
/*   Updated: 2024/03/26 10:18:00 by abdiakit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*ele_n;

	if (!f || !lst)
		return (NULL);
	n_list = NULL;
	while (lst)
	{
		ele_n = ft_lstnew(f(lst->content));
		if (!ele_n)
		{
			ft_lstclear(&n_list, del);
		}
		ft_lstadd_back(&n_list, ele_n);
		lst = lst->next;
	}
	return (n_list);
}
