/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:06:07 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/27 00:56:23 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end_of(char const *s, int len)
{
	while (s[len] == '\t' || s[len] == '\n' || s[len] == ' ')
	{
		len--;
	}
	return (len);
}

static int	start(char const *s, int end)
{
	int q;

	q = 0;
	while (q < end && (*s == '\t' || *s == ' ' || *s == '\n'))
	{
		q++;
		s++;
	}
	return (q);
}

char		*ft_strtrim(char const *s)
{
	int				len;
	int				st;
	int				end;
	unsigned char	*c;
	int				i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	end = end_of(s, len - 1);
	st = start(s, end);
	c = (unsigned char *)malloc(sizeof(char) * (end - st) + 2);
	if (!c)
		return (NULL);
	while (i <= (end - st))
	{
		c[i] = (unsigned char)s[st + i];
		i++;
	}
	c[i] = '\0';
	return ((char*)c);
}
