/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:44:34 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/11 17:25:40 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	mat_row(void **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	mat_free(void **mat)
{
	int	i;
	int	dim;

	i = 0;
	if (!mat)
		return ;
	dim = mat_row(mat);
	while (i < dim)
	{
		if (mat[i])
		{
			free(mat[i]);
			mat[i] = 0;
		}
		i++;
	}
	if (mat)
	{
		free(mat);
		mat = 0;
	}
}
