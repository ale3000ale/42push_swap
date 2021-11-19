/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:39:54 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 14:05:30 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	end_error(char *line, t_checker *ck)
{
	ck->error = 1;
	if (ck->view)
	{
		ft_putstr_fd("-----|CMD: ", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("|-----\n", 2);
	}
	free(line);
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	end_command(char *line, t_clist **a, t_clist **b, t_checker *ck)
{
	if (ck->view)
	{
		ft_putstr_fd("-----|CMD: ", 2);
		ft_putstr_fd(line, 2);
		ft_putstr_fd("|-----\n", 2);
		print_stack(*a, A);
		print_stack(*b, B);
	}
	free(line);
	return (1);
}

int	switch_commands(char *line, t_clist **a, t_clist **b, t_checker *ck)
{
	if (!ft_strncmp("sa", line, 4))
		sa(*a, 0);
	else if (!ft_strncmp("sb", line, 4))
		sb(*b, 0);
	else if (!ft_strncmp("ss", line, 4))
		ss(*a, *b, 0);
	else if (!ft_strncmp("pa", line, 4))
		pa(a, b, 0);
	else if (!ft_strncmp("pb", line, 4))
		pb(a, b, 0);
	else if (!ft_strncmp("ra", line, 4))
		ra(a, 0);
	else if (!ft_strncmp("rb", line, 4))
		rb(b, 0);
	else if (!ft_strncmp("rr", line, 4))
		rr(a, b, 0);
	else if (!ft_strncmp("rra", line, 4))
		rra(a, 0);
	else if (!ft_strncmp("rrb", line, 4))
		rrb(b, 0);
	else if (!ft_strncmp("rrr", line, 4))
		rrr(a, b, 0);
	else
		return (end_error(line, ck));
	return (end_command(line, a, b, ck));
}

int	finish(t_checker *ck, char *line)
{
	free(line);
	if (ck->view && !ck->error)
		printf("You have done: %d\n", ck->step);
	if (is_sorted(ck->a) && !ck->b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_clstclear(&ck->a, free);
	return (0);
}

int	main(int args, char **argv)
{
	char		*line;
	int			rd;
	t_checker	ck;

	if (!argument(args, argv, &ck))
		return (0);
	if (ck.view)
	{
		ft_putstr_fd("---START---\n", 1);
		print_stack(ck.a, A);
		print_stack(ck.b, B);
	}
	rd = get_next_line(0, &line);
	while (line[0] && rd != -1 && !ck.error)
	{
		ck.step += switch_commands(line, &ck.a, &ck.b, &ck);
		rd = get_next_line(0, &line);
	}
	if (ck.error)
		return (0);
	return (finish(&ck, line));
}
