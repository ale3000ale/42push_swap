/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:20:51 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/24 17:05:21 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}

void	ft_clstiter(t_clist *lst, void (*f)(void *))
{
	int	finish;

	finish = 0;
	if (lst && f)
	{
		while (!finish)
		{
			(*f)(lst->content);
			finish = lst->last;
			lst = lst->next;
		}
	}
}
