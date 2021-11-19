/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:58:52 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 13:02:08 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_swap *swap, int last, int first)
{
	int	i;
	int	n;

	i = 0;
	n = first;
	if (ft_abs(last) < ft_abs(first))
		n = last;
	while (i < ft_abs(n))
	{
		if (n < 0)
			rrb(&swap->b, 1);
		else
			rb(&swap->b, 1);
		i++;
	}
	pa(&swap->a, &swap->b, 1);
	if (ft_abs(first) <= ft_abs(last))
	{
		swap->ck[get_index(swap->a)] = 1;
		ra(&swap->a, 1);
	}
}

void	push_to_b(t_swap *swap, int last, int first)
{
	int	i;
	int	n;

	i = 0;
	n = first;
	if (ft_abs(last) < ft_abs(first))
		n = last;
	while (i < ft_abs(n))
	{
		if (n < 0)
			rra(&swap->a, 1);
		else
			ra(&swap->a, 1);
		i++;
	}
	pb(&swap->a, &swap->b, 1);
}

int	push_sort_pivot(t_swap *swap)
{
	int	pivot;
	int	*min;
	int	*max;

	min = 0;
	max = 0;
	pivot = swap->pivot_b;
	get_max_min(swap->b, &min, &max);
	while (swap->b && max[0] != pivot)
	{
		get_max_min(swap->b, &min, &max);
		push_to_a(swap, \
			find_smart_num(swap->b, ft_clstsize(swap->b), pivot, greater), \
			find_smart_num(swap->b, ft_clstsize(swap->b), min[0], equal) \
			+ (swap->len * !(min[0] <= pivot)));
	}
	return (pivot);
}

void	sort_over_pivot(t_swap *swap)
{
	while (is_in_range(point_get_int(swap->a->content), \
		swap->pivot_b + 1, swap->pivot_a))
	{
		if (get_index(swap->a->pre) + 1 < swap->len)
		{
			if (swap->supp[get_index(swap->a->pre) + 1] \
			 == point_get_int(swap->a->content))
			{
				swap->ck[get_index(swap->a)] = 1;
				ra(&swap->a, 1);
				continue ;
			}
		}
		pb(&swap->a, &swap->b, 1);
	}
}

void	sort_b(t_swap *swap)
{
	int	*min;
	int	*max;

	min = 0;
	max = 0;
	while (swap->b)
	{
		get_max_min(swap->b, &min, &max);
		push_to_a(swap, \
			find_smart_num(swap->b, ft_clstsize(swap->b), max[0], equal), \
			find_smart_num(swap->b, ft_clstsize(swap->b), min[0], equal));
	}
}
