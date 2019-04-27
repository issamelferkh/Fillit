/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:59:55 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/03/28 21:33:26 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;

	if (!*n)
		return ((char *)h);
	while (*h && len > 0)
	{
		i = 0;
		while (h[i] == n[i] && n[i] && len > i)
			i++;
		if (!n[i])
			return ((char *)h);
		h++;
		len--;
	}
	return (0);
}
