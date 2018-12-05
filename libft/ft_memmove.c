/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 22:21:31 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/26 16:51:27 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*dp;
	char const	*sp;

	dp = (char*)str1;
	sp = (char const*)str2;
	if (dp < sp)
	{
		while (n-- > 0)
			*dp++ = *sp++;
	}
	else
	{
		dp += n;
		sp += n;
		while (n-- > 0)
			*--dp = *--sp;
	}
	return (str1);
}
