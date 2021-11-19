/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 12:19:55 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/05 15:50:16 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	rra(t_clist **a, int send)
{
	t_clist	*last;

	if (a && a[0] && a[0]->next != a[0])
	{
		a[0] = a[0]->pre;
		a[0]->last = 0;
		last = a[0]->pre;
		last->last = 1;
	}
	if (send)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_clist **b, int send)
{
	t_clist	*last;

	if (b && b[0] && b[0]->next != b[0])
	{
		b[0] = b[0]->pre;
		b[0]->last = 0;
		last = b[0]->pre;
		last->last = 1;
	}
	if (send)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_clist **a, t_clist **b, int send)
{
	rra(a, 0);
	rrb(b, 0);
	if (send)
		ft_putstr_fd("rrr\n", 1);
}
