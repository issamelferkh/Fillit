/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:31:53 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/03/31 18:03:29 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t len)
{
	unsigned char *dst;

	dst = (unsigned char *)s;
	while (len)
	{
		*dst = 0;
		dst++;
		len--;
	}
	s = (void *)dst;
	return (s);
}
