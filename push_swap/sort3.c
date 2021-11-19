/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:18:51 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/11 16:19:35 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	format_down(int size, t_swap *swap)
{
	while (!swap->ck[get_index(swap->a->pre)] && size / 2 > 0)
	{
		rra(&swap->a, 1);
		size--;
	}
}

void	format_a(t_swap *swap)
{
	int	i;

	i = 0;
	i = ft_clstsize(swap->a);
	if (swap->ck[(i / 2)])
		format_down(i, swap);
	else
		format_up(i, swap);
}

int	find_smart_above(t_clist *stack, int size, int num, \
	int (*compare)(int, int))
{
	int	ck;
	int	pos;
	int	i;

	pos = size;
	i = 1;
	ck = 1;
	stack = stack->pre;
	while (i < (size / 2) + 1 && ck)
	{
		if (compare(point_get_int(stack->content), num))
		{
			pos = i;
			ck = 0;
		}
		i++;
		stack = stack->pre;
	}
	return (pos);
}

int	find_smart_top(t_clist *stack, int size, int num, int (*compare)(int, int))
{
	int	ck;
	int	pos;
	int	i;

	pos = size;
	i = 0;
	ck = 1;
	while (i < (size / 2) + 1 && ck)
	{
		if (compare(point_get_int(stack->content), num))
		{
			pos = i;
			ck = 0;
		}
		i++;
		stack = stack->next;
	}
	return (pos);
}

int	find_smart_num(t_clist *stack, int size, int num, int (*compare)(int, int))
{
	int	above;
	int	top;

	above = find_smart_above(stack, size, num, compare);
	top = find_smart_top(stack, size, num, compare);
	if (top <= above)
		return (top);
	return (-above);
}
