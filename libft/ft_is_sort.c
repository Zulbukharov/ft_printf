/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:23:39 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/30 18:43:01 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length)
	{
		if (tab[i + 1] && f(tab[i], tab[i + 1]) <= 0)
			i++;
		else if (i + 1 == length)
			return (1);
		else
			return (0);
	}
	return (1);
}
