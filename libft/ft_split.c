/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:46:26 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/12 18:41:32 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*destroy(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i] != NULL)
		free(strs[i]);
	free(strs);
	return (NULL);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*clone;
	size_t	len;

	clone = (char *)malloc(sizeof(char) * (n + 1));
	if (!clone)
		return (0);
	clone[n] = '\0';
	len = ft_strlen(s1);
	if (n < len)
		ft_memcpy(clone, s1, n);
	else
		ft_memcpy(clone, s1, len);
	if (len < n)
		ft_bzero(clone + len, n - len);
	return (clone);
}

size_t	segment(char const *s, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

int	splitter(char const *s, char c, char ***strs)
{
	int	segments;

	if (!s)
		return (0);
	segments = segment(s, c);
	*strs = (char **)malloc(sizeof(char *) * (segments + 1));
	if (!strs)
		return (0);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	segments;
	size_t	i;
	size_t	j;

	if (!splitter(s, c, &strs))
		return (0);
	segments = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		strs[segments++] = ft_strndup(&s[j], i);
		if (!strs)
			return (destroy(strs));
		j += i - 1;
	}
	strs[segments] = 0;
	return (strs);
}
