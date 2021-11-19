/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:23:01 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/28 18:46:35 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (lst[0])
			new->next = lst[0];
		lst[0] = new;
	}
}

void	ft_clstadd_front(t_clist **lst, t_clist *new)
{
	if (lst)
	{
		if (lst[0])
		{
			new->next = lst[0];
			new->pre = lst[0]->pre;
			new->last = 0;
			lst[0]->pre = new;
			new->pre->next = new;
			lst[0] = new;
		}
		else
		{
			lst[0] = new;
			new->last = 1;
		}
	}
}
