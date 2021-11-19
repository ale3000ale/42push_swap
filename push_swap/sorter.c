/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:52:35 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/12 18:49:28 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(int *array, int begin, int end)
{
	int	pivot;
	int	l;
	int	r;

	if (end > begin)
	{
		pivot = array[begin];
		l = begin + 1;
		r = end + 1;
		while (l < r)
		{
			if (array[l] < pivot)
				l++;
			else
			{
				r--;
				ft_swap(&array[l], &array[r]);
			}
		}
		l--;
		ft_swap(&array[begin], &array[l]);
		quick_sort(array, begin, l);
		quick_sort(array, r, end);
	}
}

int	is_sorted(t_clist *ls)
{
	int	pre;

	pre = point_get_int(ls->content);
	ls = ls->next;
	while (!ls->pre->last)
	{
		if (point_get_int(ls->content) < pre)
			return (0);
		pre = point_get_int(ls->content);
		ls = ls->next;
	}
	return (1);
}

int	print_stack(t_clist *stack, char *name)
{
	char	*n;

	ft_putstr_fd(name, 1);
	ft_putstr_fd("|->", 1);
	if (!stack)
		return (ft_putstr_fd("\n", 1));
	n = ft_itoa(point_get_int(stack->content));
	ft_putstr_fd(n, 1);
	free(n);
	stack = stack->next;
	while (!stack->pre->last)
	{
		ft_putstr_fd("->", 1);
		n = ft_itoa(point_get_int(stack->content));
		ft_putstr_fd(n, 1);
		free(n);
		stack = stack->next;
	}
	return (ft_putstr_fd("\n", 1));
}

void	move(t_swap *swap)
{
	set_index(*swap, swap->a);
	while (!is_sorted(swap->a))
	{
		swap->pivot_a = load_b(swap);
		format_a(swap);
		swap->pivot_b = push_sort_pivot(swap);
		if (ft_clstsize(swap->b))
		{
			sort_b(swap);
			shift_a(swap, 0);
		}
		sort_over_pivot(swap);
		if (ft_clstsize(swap->b))
		{
			sort_b(swap);
			shift_a(swap, 1);
		}
	}
}
