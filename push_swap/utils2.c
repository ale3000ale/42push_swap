/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:22:00 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/11 16:23:25 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_swap swap, int n)
{
	int	i;

	i = 0;
	while (i < swap.len)
	{
		if (swap.supp[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int	get_second_pivot(t_swap swap)
{
	int	i2;
	int	idx;

	idx = find_index(swap, swap.pivot_a);
	i2 = idx;
	while (!swap.ck[--i2] && i2)
		continue ;
	if (i2)
		i2++;
	i2 = ((idx - i2) / 2) + i2 + ((idx - i2) % 2);
	i2 = swap.supp[i2];
	return (i2);
}

int	ft_abs(int a)
{
	return (a * (1 - (2 * (a < 0))));
}
