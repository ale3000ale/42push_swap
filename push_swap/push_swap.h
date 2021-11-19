/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:40:00 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/12 18:21:12 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>

# include "../libft/libft.h"
# include "../command/command.h"

typedef struct s_swap
{
	int		*supp;
	int		*ck;
	int		len;
	t_clist	*a;
	t_clist	*b;
	int		pivot_a;
	int		pivot_b;
}	t_swap;

//--------SORTING-------------

int		load_b(t_swap *swap);
void	format_a(t_swap *swap);
int		push_sort_pivot(t_swap *swap);
void	sort_over_pivot(t_swap *swap);
void	sort_b(t_swap *swap);
void	shift_a(t_swap *swap, int phase);
void	sort3(t_swap *swap);
void	sort5(t_swap *swap);

//--------SORTING UTILS-------

void	quick_sort(int *array, int begin, int end);
void	move(t_swap *swap);
int		find_smart_num(t_clist *stack, int size, int num, \
		int (*compare)(int, int));
void	format_up(int size, t_swap *swap);
void	push_to_b(t_swap *swap, int last, int first);

//--------UTILS---------------

int		is_sorted(t_clist *ls);
int		get_first_pivot(t_swap *swap);
int		get_second_pivot(t_swap swap);
int		set_index(t_swap sp, t_clist *stack);
int		get_index(t_clist *stack);
void	get_max_min(t_clist *stack, int **min, int **max);
int		ft_abs(int a);
void	mat_free(void **mat);
size_t	mat_row(void **str);

//--------COMPARE----------

int		equal(int a, int b);
int		greater(int a, int b);
int		lower(int a, int b);
int		greater_eq(int a, int b);
int		lower_eq(int a, int b);
int		is_in_range(int n, int a, int b);

//--------INIT-----------

int		new_stack(t_clist **stack, char **s, int n, t_swap *sp);
int		init1(char **argv, t_swap *swap);
int		initx(int args, char **argv, t_swap *swap);

int		print_stack(t_clist *stack, char *name);
#endif
