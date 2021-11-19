/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:02:08 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 14:45:24 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				return (ft_putstr_fd("Error\n", 1) * 0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ck_arg(char *s)
{
	char	**spl;
	int		i;
	long	ck_int;

	i = 0;
	spl = ft_split(s, ' ');
	while (spl[i])
	{
		ck_int = ft_latoi(spl[i]);
		if (ck_int > INT32_MAX || ck_int < INT32_MIN \
			|| !ft_strdigit(&spl[i][(spl[i][0] == '-')]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (spl);
}

int	ck_args(char **s, int n)
{
	int		i;
	long	ck;

	i = 0;
	while (i < n)
	{
		ck = ft_latoi(s[i]);
		if (ck > INT32_MAX || ck < INT32_MIN \
			|| !ft_strdigit(&s[i][(s[i][0] == '-')]))
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init1(char **argv, t_swap *swap)
{
	char	**spl;

	spl = ck_arg(argv[1]);
	if (spl && aredup(spl, mat_row((void **)spl)))
	{
		swap->len = mat_row((void **)spl);
		swap->ck = ft_calloc(swap->len, sizeof(int));
		swap->supp = malloc(sizeof(int) * (swap->len));
		new_stack(&(swap->a), spl, swap->len, swap);
		mat_free((void **) spl);
	}
	else
	{
		mat_free((void **)spl);
		return (0);
	}
	return (1);
}

int	initx(int args, char **argv, t_swap *swap)
{
	swap->len = args - 1;
	swap->ck = ft_calloc(args - 1, sizeof(int));
	swap->supp = malloc(sizeof(int) * (args - 1));
	if ((!swap->supp || !swap->ck) \
		|| !aredup(&argv[1], args - 1))
	{
		free(swap->ck);
		free(swap->supp);
		return (0);
	}
	if (ck_args(&argv[1], args - 1))
		new_stack(&(swap->a), &argv[1], args - 1, swap);
	else
	{
		free(swap->ck);
		free(swap->supp);
		return (0);
	}
	return (1);
}
