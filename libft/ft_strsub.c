/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 22:32:01 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/29 20:30:27 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlenq(const char *s)
{
	int d;

	d = 0;
	while (*s)
	{
		d++;
		s++;
	}
	return (d);
}

static void		make_malloc(char const *s, unsigned int start,
		unsigned int len, char *n)
{
	while (*(s + start) && len)
	{
		*n = *(s + start);
		start++;
		len--;
		n++;
	}
	*n = '\0';
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	c;
	char			*n;

	c = 0;
	if (!s || (int)start > ft_strlenq(s))
		return (0);
	while (*(s + start))
	{
		start++;
		c++;
	}
	if (len > c)
		return (NULL);
	start -= c;
	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!n)
		return (NULL);
	c = len;
	make_malloc(s, start, len, n);
	return (n);
}
