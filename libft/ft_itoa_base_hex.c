/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:23:40 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/03 21:07:22 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_10_16(unsigned long long nbr)
{
	char	*result;
	int		bits;
	int		result_len;
	int		i;
	char	hex[16];

	i = 0;
	bits = count_bits(nbr);
	result_len = (bits % 4 == 0) ? (bits / 4) : ((bits / 4) + 1);
	result = ft_strnew(result_len);
	ft_strcpy(hex, "0123456789abcdef");
	while (i < result_len)
	{
		result[i] = hex[(nbr % 16)];
		nbr >>= 4;
		i++;
	}
	ft_reverse_bitwise(result);
	return (result);
}
