/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:48:35 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/03/29 21:01:08 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*str;

	str = malloc(len);
	if (str == NULL)
		return (dst);
	ft_memcpy(str, src, len);
	ft_memcpy(dst, str, len);
	return (dst);
}
