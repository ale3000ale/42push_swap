/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:21:20 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/12 18:23:31 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	if (!str1 && !str2)
		return (0);
	ds = (unsigned char *)str1;
	sr = (unsigned char *)str2;
	if (str2 >= str1)
	{
		i = 0;
		while (i < n)
		{
			ds[i] = sr[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			ds[n] = sr[n];
	}
	return (ds);
}
