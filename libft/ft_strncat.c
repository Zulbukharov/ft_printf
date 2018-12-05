/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 21:16:26 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/21 21:26:17 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *app, size_t n)
{
	char *d;

	d = dest;
	while (*d)
		d++;
	while (*app && n)
	{
		*d = *app;
		d++;
		n--;
		app++;
	}
	*d = '\0';
	return (dest);
}
