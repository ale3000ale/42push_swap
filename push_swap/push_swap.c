/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:35:55 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 13:15:42 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_last_number(t_clist **stack, char *s, int *array)
{
	int		*num;

	num = malloc(sizeof(int) * 2);
	if (!num)
	{
		ft_clstclear(stack, free);
		return (0);
	}
	*num = ft_atoi(s);
	ft_clstadd_back(stack, ft_clstnew((void *)num));
	array[0] = *num;
	return (1);
}

int	new_stack(t_clist **stack, char **s, int n, t_swap *sp)
{
	int		i;

	i = 1;
	if (!add_last_number(stack, s[0], &sp->supp[0]))
		return (0);
	while (i < n)
	{
		if (!add_last_number(stack, s[i], &sp->supp[i]))
			return (0);
		i++;
	}
	ft_clstlast(*stack)->next = *stack;
	return (1);
}

int	main(int args, char **argv)
{
	t_swap	swap;

	if (args == 1 || (args == 2 && !argv[1][0]))
		return (0);
	if (args == 2)
	{
		if (!init1(argv, &swap))
			return (0);
	}
	else if (!initx(args, argv, &swap))
		return (0);
	swap.b = 0;
	quick_sort(swap.supp, 0, swap.len - 1);
	if (swap.len == 2 && !is_sorted(swap.a))
		sa(swap.a, 1);
	else if (swap.len == 3 && !is_sorted(swap.a))
		sort3(&swap);
	else if (swap.len == 5 && !is_sorted(swap.a))
		sort5(&swap);
	else
		move(&swap);
	ft_clstclear(&swap.a, free);
	free(swap.ck);
	free(swap.supp);
	return (0);
}
