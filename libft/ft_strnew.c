/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:13:40 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/29 14:18:31 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char				*s;
	unsigned int		d;

	d = 0;
	s = (void *)malloc(size + 1);
	if (!s)
		return (NULL);
	while (d < size)
	{
		s[d] = '\0';
		d++;
	}
	s[d] = '\0';
	return (s);
}
