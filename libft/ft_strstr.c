/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:10:56 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/26 21:09:53 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		str_in_str(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (0);
	}
	if (*s2)
		return (0);
	return (1);
}

char			*ft_strstr(const char *s1, const char *s2)
{
	int p;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		if (*s1 == *s2)
		{
			p = str_in_str(s1, s2);
			if (p == 1)
				return ((char*)s1);
		}
		s1++;
	}
	return (NULL);
}
