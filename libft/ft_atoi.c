/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 14:08:35 by amarcell          #+#    #+#             */
/*   Updated: 2021/05/13 13:57:29 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' \
	 || c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ret(int sign, int size, int result)
{
	if (size > 10 && sign > 0)
		return (-1);
	else if (size > 10 && sign < 0)
		return (0);
	return ((int)(sign * result));
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		result;
	int		size;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	size = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
		size++;
	}
	return (ret(sign, size, result));
}

long	lret(int sign, int size, long result)
{
	if (size > 10 && sign > 0)
		return (-1);
	else if (size > 15 && sign < 0)
		return (0);
	return ((long)(sign * result));
}

long	ft_latoi(const char *str)
{
	int		i;
	int		sign;
	long	result;
	int		size;

	result = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	size = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
		size++;
	}
	return (lret(sign, size, result));
}
