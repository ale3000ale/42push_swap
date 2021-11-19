/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:46:06 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/06 15:48:58 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_clstsize(t_clist *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (!lst->last || !i)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
