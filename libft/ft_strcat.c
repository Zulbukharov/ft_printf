/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:24:10 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:52:35 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcat(char *dest, const char *app)
{
	char *d;

	d = dest;
	while (*d)
		d++;
	while (*app)
	{
		*d = *app;
		app++;
		d++;
	}
	*d = '\0';
	return (dest);
}
