/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:29:20 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/05 15:50:47 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# define	SA	=	0
# define	SB	=	1
# define	SS	=	2
# define	PA	=	3
# define	PB	=	4
# define	RA	=	5
# define	RB	=	6
# define	RR	=	7
# define	RRA	=	8
# define	RRB	=	9
# define	RRR	=	10

# include<stdio.h>
# include "../libft/libft.h"

int		point_get_int(void *point);
void	point_set_int(void *point, int n);
int		*int_dup(int n);
void	sa(t_clist *a, int send);
void	sb(t_clist *b, int send);
void	ss(t_clist *a, t_clist *b, int send);
void	pa(t_clist **a, t_clist **b, int send);
void	pb(t_clist **a, t_clist **b, int send);
void	ra(t_clist **a, int send);
void	rb(t_clist **b, int send);
void	rr(t_clist **a, t_clist **b, int send);
void	rrr(t_clist **a, t_clist **b, int send);
void	rrb(t_clist **b, int send);
void	rra(t_clist **a, int send);
int		point_get_int(void *point);
void	point_set_int(void *point, int n);
int		*int_dup(int n);

#endif
