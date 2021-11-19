/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:20:35 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 14:01:52 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*first;

	if (lst)
	{
		if (lst[0])
		{
			first = *lst;
			lst[0] = ft_lstlast(lst[0]);
			(lst[0])->next = new;
			*lst = first;
		}
		else
			lst[0] = new;
	}
}

void	ft_clstadd_back(t_clist **lst, t_clist *new)
{
	t_clist	*first;

	if (lst)
	{
		if (lst[0])
		{
			first = *lst;
			lst[0] = ft_clstlast(lst[0]);
			new->next = lst[0]->next;
			(lst[0])->next = new;
			new->pre = lst[0];
			(*lst)->last = 0;
			new->last = 1;
			new->next->pre = new;
			*lst = first;
		}
		else
			lst[0] = new;
	}
}
