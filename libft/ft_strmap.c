/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:22:24 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/01 20:13:25 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*cpy;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((cpy = ft_strnew(ft_strlen((char *)s))))
	{
		while (s[i])
		{
			cpy[i] = f(s[i]);
			i++;
		}
		return (cpy);
	}
	return (NULL);
}
