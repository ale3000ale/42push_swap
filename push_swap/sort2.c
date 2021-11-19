/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:14:15 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 13:13:44 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lower(t_clist *stack, int pivot)
{
	int	*min;
	int	*max;

	min = 0;
	max = 0;
	get_max_min(stack, &min, &max);
	return (pivot >= min[0]);
}

int	get_next_lower_id(t_swap *swap)
{
	int	i;

	i = 0;
	while (swap->ck[i] && i < swap->len)
		i++;
	return (i);
}

void	push_down_lower(t_swap *swap)
{
	pb(&swap->a, &swap->b, 1);
	if (point_get_int(swap->b->content) <= swap->pivot_b)
	{
		if (swap->b != swap->b->pre)
		{
			if (!swap->ck[get_index(swap->a)] && find_lower(swap->a, \
				swap->pivot_a) \
				&& point_get_int(swap->a->content) > swap->pivot_a)
				rr(&swap->a, &swap->b, 1);
		}
	}
}

int	load_b(t_swap *swap)
{
	int	ck;

	swap->pivot_a = get_first_pivot(swap);
	if (!swap->ck[(int)((swap->len) * 0.62)] && swap->len >= 250)
	{
		swap->pivot_a = get_second_pivot(*swap);
		if (!swap->ck[(int)((swap->len) * 0.05)] && swap->len >= 500)
			swap->pivot_a = get_second_pivot(*swap);
	}
	swap->pivot_b = get_second_pivot(*swap);
	ck = 0;
	while (ck < swap->len && !swap->ck[get_index(swap->a)] \
	 && find_lower(swap->a, swap->pivot_a))
	{
		if (point_get_int(swap->a->content) <= swap->pivot_a)
			push_down_lower(swap);
		else
			ra(&swap->a, 1);
		ck++;
	}
	return (swap->pivot_a);
}

void	format_up(int size, t_swap *swap)
{
	while (swap->ck[get_index(swap->a)] && size / 2 > 0)
	{
		ra(&swap->a, 1);
		size--;
	}
}
