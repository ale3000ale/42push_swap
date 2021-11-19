/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:50:46 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/06 16:23:59 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	equal(int a, int b)
{
	return (a == b);
}

int	greater(int a, int b)
{
	return (a > b);
}

int	lower(int a, int b)
{
	return (a < b);
}

int	greater_eq(int a, int b)
{
	return (a >= b);
}

int	lower_eq(int a, int b)
{
	return (a <= b);
}
