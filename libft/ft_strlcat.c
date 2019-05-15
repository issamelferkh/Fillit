/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:11:21 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/03 22:13:50 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		dst_len++;
		size--;
	}
	while (*src && size > 1)
	{
		size--;
		*dst++ = *src++;
	}
	if (size == 1 || *src == 0)
		*dst = 0;
	return (src_len + dst_len);
}
