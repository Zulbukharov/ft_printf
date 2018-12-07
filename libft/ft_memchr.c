/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:40:13 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:51:41 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memchr(const void *dest, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char*)dest;
	while (i < n)
	{
		if (*d == (unsigned char)c)
			return (d);
		d++;
		n--;
	}
	return (NULL);
}
