/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 16:00:03 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/21 20:22:34 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlenq(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *src)
{
	int		i;
	int		ind;
	char	*str;

	ind = 0;
	i = ft_strlenq(src);
	if (i >= 0)
	{
		str = (char *)malloc(i + 1);
		if (str == NULL)
			return (0);
		while (src[ind] != '\0')
		{
			str[ind] = src[ind];
			ind++;
		}
		str[ind] = '\0';
		return (str);
	}
	else
		return (0);
}
