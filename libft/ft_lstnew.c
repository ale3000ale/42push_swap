/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:02:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/24 17:10:01 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (0);
	l->content = content;
	l->next = 0;
	return (l);
}

t_clist	*ft_clstnew(void *content)
{
	t_clist	*l;

	l = (t_clist *)malloc(sizeof(t_clist));
	if (!l)
		return (0);
	l->content = content;
	l->next = l;
	l->pre = l;
	l->last = 1;
	return (l);
}
