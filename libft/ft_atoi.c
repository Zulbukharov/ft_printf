/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 04:34:52 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/05 23:45:48 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int n;
	long long int t;

	n = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -1;
		str++;
	}
	t = 0;
	while (*str >= '0' && *str <= '9' && t >= 0)
	{
		t = (t * 10) + ((long long int)*str - 48);
		str++;
	}
	if (t < 0)
	{
		if (n < 0)
			return (0);
		return (-1);
	}
	return ((int)t * (int)n);
}
