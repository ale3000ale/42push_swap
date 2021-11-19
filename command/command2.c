/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:36:54 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/05 15:49:57 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void	ra(t_clist **a, int send)
{
	t_clist	*last;

	if (a && a[0] && a[0]->next != a[0])
	{
		last = a[0]->pre;
		a[0]->last = 1;
		last->last = 0;
		a[0] = a[0]->next;
	}
	if (send)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_clist **b, int send)
{
	t_clist	*last;

	if (b && b[0] && b[0]->next != b[0])
	{
		last = b[0]->pre;
		b[0]->last = 1;
		last->last = 0;
		b[0] = b[0]->next;
	}
	if (send)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_clist **a, t_clist **b, int send)
{
	ra(a, 0);
	rb(b, 0);
	if (send)
		ft_putstr_fd("rr\n", 1);
}
