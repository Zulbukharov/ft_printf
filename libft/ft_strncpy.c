/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:33:37 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/27 17:18:02 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest1, char *src1, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src1[i] && n)
	{
		if (!n--)
			return (dest1);
		dest1[i] = src1[i];
		i++;
	}
	while (n--)
	{
		dest1[i] = '\0';
		i++;
	}
	return (dest1);
}
