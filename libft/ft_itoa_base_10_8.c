/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_10_8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:47:15 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/03 21:03:38 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_10_8(unsigned long long nbr)
{
	char	*result;
	int		bits;
	int		result_len;
	int		i;

	i = 0;
	bits = count_bits(nbr);
	result_len = (bits % 3 == 0) ? (bits / 3) : ((bits / 3) + 1);
	result = ft_strnew(result_len);
	while (i < result_len)
	{
		result[i] = (nbr & 7) + '0';
		nbr >>= 3;
		i++;
	}
	ft_reverse_bitwise(result);
	return (result);
}
