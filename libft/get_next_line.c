/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcell <amarcell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:49:46 by amarcell          #+#    #+#             */
/*   Updated: 2021/04/28 17:41:18 by amarcell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include "libft.h"

int	get_next_line(int fd, char **line)
{
	char	buff[2];
	char	*temp;
	int		rd;

	if (fd < 0 || !line)
		return (-1);
	*line = ft_calloc(1, 1);
	if (!(*line))
		return (-1);
	buff[0] = 0;
	buff[1] = 0;
	rd = read(fd, buff, 1) > 0;
	while (rd)
	{
		if (buff[0] == '\n')
			return (1);
		if (rd == -1)
			return (-1);
		temp = *line;
		*line = ft_strjoin(temp, buff);
		free(temp);
		rd = read(fd, buff, 1) > 0;
	}
	return (0);
}
