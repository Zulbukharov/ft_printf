/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:28:21 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 17:50:48 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_isupper(int ch)
{
	if (!ch)
		return (0);
	if (ch >= 65 && ch <= 90)
		return (1);
	return (0);
}
