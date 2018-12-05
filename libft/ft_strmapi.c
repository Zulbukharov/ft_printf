/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 21:48:27 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/22 21:55:39 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	c;
	unsigned int	b;
	char			*s1;

	c = 0;
	b = 0;
	if (!s || !f || !*s)
		return (NULL);
	while (*s)
	{
		s++;
		c++;
	}
	s1 = (char *)malloc(sizeof(char) * (c + 1));
	if (!s1)
		return (NULL);
	s -= c;
	while (b < c)
	{
		s1[b] = f(b, *s);
		b++;
		s++;
	}
	s1[b] = '\0';
	return (s1);
}
