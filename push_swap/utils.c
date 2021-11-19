/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:52:18 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/11 16:23:40 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_supp_index(int n, t_swap sp)
{
	int	i;

	i = 0;
	while (i < sp.len)
		if (sp.supp[i++] == n)
			return (--i);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int	get_index(t_clist *stack)
{
	return (((int *)(stack->content))[1]);
}

int	set_index(t_swap sp, t_clist *stack)
{
	int	ck;
	int	ind;

	ck = 1;
	while (ck)
	{
		if (stack->last)
			ck = 0;
		ind = get_supp_index(*(int *)(stack->content), sp);
		if (ind != -1)
			((int *)(stack->content))[1] = ind;
		stack = stack->next;
	}
	return (1);
}

void	get_max_min(t_clist *stack, int **min, int **max)
{
	int	ck;

	ck = 1;
	*min = (int *)stack->content;
	*max = (int *)stack->content;
	while (ck)
	{
		if (stack->last)
			ck = 0;
		if (point_get_int(stack->content) < (*min)[0])
			*min = (int *)stack->content;
		if (point_get_int(stack->content) > (*max)[0])
			*max = (int *)stack->content;
		stack = stack->next;
	}
}

int	get_first_pivot(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->len)
		if (!swap->ck[i++])
			break ;
	if (swap->len > 1 && i == swap->len)
		i = swap->supp[swap->len - 1];
	else
		i = swap->supp[((swap->len - i) / 2) + i - (i % 2)];
	return (i);
}
