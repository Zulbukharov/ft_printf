/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 21:12:12 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:53:31 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			return (*(unsigned char*)(s1) - *(unsigned char*)(s2));
		else if (!*s1 || !*s2)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
