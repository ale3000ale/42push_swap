/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:20:37 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 12:59:40 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shift_a(t_swap *swap, int phase)
{
	int	pv;

	pv = swap->pivot_b;
	if (phase)
		pv = swap->pivot_a;
	while (point_get_int(swap->a->content) <= pv \
			&& point_get_int(swap->a->pre->content) != pv)
	{
		swap->ck[get_index(swap->a)] = 1;
		ra(&swap->a, 1);
	}
}

void	sort3(t_swap *swap)
{
	if (!is_sorted(swap->a))
	{
		if (point_get_int(swap->a->content) == swap->supp[0])
		{
			ra(&swap->a, 1);
			sa(swap->a, 1);
			rra(&swap->a, 1);
		}
		else if (point_get_int(swap->a->next->content) == swap->supp[1])
		{
			rra(&swap->a, 1);
			sa(swap->a, 1);
			ra(&swap->a, 1);
		}
		else if (point_get_int(swap->a->pre->content) == swap->supp[2])
			sa(swap->a, 1);
		else
		{
			rra(&swap->a, 1);
			if (!is_sorted(swap->a))
				sort3(swap);
		}
	}
}

void	sort3on5(t_swap *swap)
{
	if (!is_sorted(swap->a))
	{
		if (point_get_int(swap->a->content) == swap->supp[2])
		{
			ra(&swap->a, 1);
			sa(swap->a, 1);
			rra(&swap->a, 1);
		}
		else if (point_get_int(swap->a->next->content) == swap->supp[3])
		{
			rra(&swap->a, 1);
			sa(swap->a, 1);
			ra(&swap->a, 1);
		}
		else if (point_get_int(swap->a->pre->content) == swap->supp[4])
			sa(swap->a, 1);
		else
		{
			rra(&swap->a, 1);
			if (!is_sorted(swap->a))
				sort3on5(swap);
		}
	}
}

void	sort5(t_swap *swap)
{
	int	*min;
	int	*max;

	min = 0;
	max = 0;
	get_max_min(swap->a, &min, &max);
	push_to_b(swap, \
		find_smart_num(swap->a, 5, swap->supp[0], equal), \
		find_smart_num(swap->a, 5, swap->supp[1], equal));
	get_max_min(swap->a, &min, &max);
	if (min[0] <= swap->supp[1])
		push_to_b(swap, \
			find_smart_num(swap->a, 5, min[0], equal), \
			10);
	sort3on5(swap);
	if (point_get_int(swap->b->content) != swap->supp[1])
		sb(swap->b, 1);
	pa(&swap->a, &swap->b, 1);
	pa(&swap->a, &swap->b, 1);
}
