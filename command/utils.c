/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:02:11 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/30 13:39:11 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

int	point_get_int(void *point)
{
	return (*((int *)(point)));
}

void	point_set_int(void *point, int n)
{
	*((int *)(point)) = n;
}

int	*int_dup(int n)
{
	int	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (0);
	*new = n;
	return (new);
}
