/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:42:15 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/29 14:29:23 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	int		b;
	char	*s1;

	c = 0;
	b = 0;
	if (!s || !f || !*s || !*f)
		return (NULL);
	while (s[c])
		c++;
	s1 = (char *)malloc(sizeof(char) * (c + 1));
	if (!s1)
		return (NULL);
	while (b < c)
	{
		s1[b] = f(s[b]);
		b++;
	}
	s1[b] = '\0';
	return (s1);
}
