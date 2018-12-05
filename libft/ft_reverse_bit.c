/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:21:58 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/01 23:22:07 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_bitwise(char *str)
{
	int		last;
	int		i;

	i = 0;
	last = ft_strlen(str) - 1;
	if (!str || !*str || last == -1)
		return (str);
	while (i < last)
	{
		str[i] ^= str[last];
		str[last] ^= str[i];
		str[i] ^= str[last];
		i++;
		last--;
	}
	return (str);
}
