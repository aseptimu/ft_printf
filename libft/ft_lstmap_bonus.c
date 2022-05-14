/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseptimu <aseptimu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:59:08 by aseptimu          #+#    #+#             */
/*   Updated: 2021/11/02 20:59:08 by aseptimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*cpyl;

	cpyl = (void *)0;
	while (lst)
	{
		newl = ft_lstnew(f(lst->content));
		if (!newl)
		{
			ft_lstclear(&cpyl, del);
			return ((void *)0);
		}
		ft_lstadd_back(&cpyl, newl);
		lst = lst->next;
	}
	return (cpyl);
}
