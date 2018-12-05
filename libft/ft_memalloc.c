/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 17:43:46 by azulbukh          #+#    #+#             */
/*   Updated: 2018/03/29 20:33:06 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void	*block;

	if (!n)
		return (NULL);
	block = (void *)malloc(n);
	if (!block)
		return (NULL);
	ft_bzero(block, n);
	return (block);
}
