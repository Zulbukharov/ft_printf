/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:12:39 by azulbukh          #+#    #+#             */
/*   Updated: 2018/04/23 19:57:12 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_add_to_line(char *i, char **line, t_node *cache)
{
	char *temp;
	char *temp1;

	if (i)
	{
		temp = ft_strsub(cache->r, 0, i - cache->r);
		cache->size -= (i - cache->r) + 1;
		ft_memmove(cache->r, i + 1, cache->size + 1);
	}
	else
	{
		temp = ft_strdup(cache->r);
		cache->size = 0;
	}
	temp1 = *line;
	if (temp1)
	{
		*line = ft_strjoin(temp1, temp);
		free(temp1);
		free(temp);
	}
	else
		*line = temp;
}

int			ft_get_next_line(const int fd, char **line)
{
	char			*i;
	static t_node	pit[10000];

	i = NULL;
	if (!line || (!(*line = 0) && (fd < 0 || fd > 9999)) ||
			read(fd, NULL, 0) < 0)
		return (-1);
	while (!i)
	{
		if (!pit[fd].size &&
				(pit[fd].size = read(fd, pit[fd].r, BUFF_SIZE)) < 1)
		{
			if (*line)
				return (1);
			else
				return (pit[fd].size);
		}
		pit[fd].r[pit[fd].size] = 0;
		i = ft_strchr(pit[fd].r, 10);
		ft_add_to_line(i, line, &pit[fd]);
	}
	return (1);
}
