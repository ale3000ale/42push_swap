/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:05:03 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 14:45:24 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
			mat_free((void **)spl);
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

int	init1(char *argv, t_clist **a)
{
	char	**spl;

	spl = ck_arg(argv);
	if (spl && aredup(spl, mat_row((void **)spl)))
	{
		new_stack(a, spl, mat_row((void **)spl));
		mat_free((void **)spl);
	}
	else
	{
		mat_free((void **)spl);
		return (0);
	}
	return (1);
}

int	initx(int args, char **argv, t_clist **a)
{
	if (ck_args(argv, args - 1) && aredup(&argv[0], args - 1))
		new_stack(a, argv, args - 1);
	else
		return (0);
	return (1);
}

int	argument(int args, char **argv, t_checker *ck)
{
	ck->step = 0;
	ck->b = 0;
	ck->view = 0;
	if (args >= 2 && !ft_strncmp(argv[1], "-v", 3))
	{
		if ((args == 2 && !argv[2][0]))
			return (0);
		args--;
		ck->view = 1;
	}
	if (args == 1 || (args == 2 && !argv[1][0]))
		return (0);
	else if (args == 2)
	{
		if (!init1(argv[1 + ck->view], &ck->a))
			return (ft_putstr_fd("Error\n", 2) * 0);
	}
	else if (args > 2 && !initx(args, &argv[1 + ck->view], &ck->a))
		return (ft_putstr_fd("Error\n", 2) * 0);
	return (1);
}
