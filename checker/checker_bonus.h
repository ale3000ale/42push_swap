/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:39:57 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 14:42:16 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include<stdio.h>
# include<time.h>

# include "../libft/libft.h"
# include "../command/command.h"

# define A		"A"
# define B		"B"

typedef struct s_checker
{
	int		step;
	int		view;
	int		error;
	t_clist	*a;
	t_clist	*b;
}				t_checker;

int		print_stack(t_clist *stack, char *name);
int		add_last_number(t_clist **stack, char *s);
int		new_stack(t_clist **stack, char **s, int n);
size_t	mat_row(void **str);
void	mat_free(void **mat);
int		argument(int args, char **argv, t_checker *ck);
int		is_sorted(t_clist *ls);
char	aredup(char **s, int size);

#endif
