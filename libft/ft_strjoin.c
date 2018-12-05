/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:26:08 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/23 20:15:12 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cmp_it(char const *s1, unsigned int *n, unsigned int cq, char *cop)
{
	while (*s1 && *n < cq)
	{
		*cop = *s1;
		cop++;
		(*n)++;
		s1++;
	}
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	c;
	unsigned int	q;
	unsigned int	n;
	char			*cop;

	c = 0;
	q = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[c])
		c++;
	while (s2[q])
		q++;
	cop = (char *)malloc(sizeof(char) * (c + q) + 1);
	if (!cop)
		return (NULL);
	cmp_it(s1, &n, (c + q), cop);
	cmp_it(s2, &n, (c + q), cop + n);
	*(cop + c + q) = '\0';
	return (cop);
}
