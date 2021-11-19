/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:25:00 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/05 15:49:33 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	sa(t_clist *a, int send)
{
	void	*temp;

	if (a->next)
	{
		temp = a->content;
		a->content = a->next->content;
		a->next->content = temp;
	}
	if (send)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_clist *b, int send)
{
	void	*temp;

	if (b->next)
	{
		temp = b->content;
		b->content = b->next->content;
		b->next->content = temp;
	}
	if (send)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_clist *a, t_clist *b, int send)
{
	sa(a, 0);
	sb(b, 0);
	if (send)
		ft_putstr_fd("ss\n", 1);
}

void	pb(t_clist **a, t_clist **b, int send)
{
	t_clist	*temp;

	if (a && a[0])
	{
		temp = a[0];
		a[0] = a[0]->next;
		if (temp->last)
			a[0] = 0;
		ft_clstadd_front(b, ft_clst_export(temp));
	}
	if (send)
		ft_putstr_fd("pb\n", 1);
}

void	pa(t_clist **a, t_clist **b, int send)
{
	t_clist	*temp;

	if (b && b[0])
	{
		temp = b[0];
		b[0] = b[0]->next;
		if (temp->last)
			b[0] = 0;
		ft_clstadd_front(a, ft_clst_export(temp));
	}
	if (send)
		ft_putstr_fd("pa\n", 1);
}
