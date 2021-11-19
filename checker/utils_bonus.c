/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:54:39 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 14:05:43 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	aredup(char **s, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (i < size && j < size)
		{
			if (!ft_strncmp(s[i], s[j], 10))
			{
				return (0);
			}
			j++;
		}
		i++;
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

int	add_last_number(t_clist **stack, char *s)
{
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
	{
		ft_clstclear(stack, free);
		return (0);
	}
	*num = ft_atoi(s);
	ft_clstadd_back(stack, ft_clstnew((void *)num));
	return (1);
}

int	new_stack(t_clist **stack, char **s, int n)
{
	int		i;

	i = 1;
	if (!add_last_number(stack, s[0]))
		return (0);
	while (i < n)
	{
		if (!add_last_number(stack, s[i]))
			return (0);
		i++;
	}
	ft_clstlast(*stack)->next = *stack;
	return (1);
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
