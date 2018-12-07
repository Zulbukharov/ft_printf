/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:21:32 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:49:57 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		count_bits(unsigned long long nbr)
{
	int		i;

	i = 0;
	while (nbr)
	{
		nbr = nbr >> 1;
		i++;
	}
	return (i);
}
