/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:58:59 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:50:02 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_count_digits(int value, int base)
{
	long	temp;
	int		ans;

	temp = value;
	temp = temp < 0 ? -temp : temp;
	ans = 0;
	if (temp == 0)
		return (1);
	while (temp != 0)
	{
		ans++;
		temp /= base;
	}
	return (ans);
}
