/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:23:08 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/01 20:15:17 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((cpy = ft_strnew(ft_strlen((char *)s))))
	{
		while (s[i])
		{
			cpy[i] = f(i, s[i]);
			i++;
		}
		return (cpy);
	}
	return (NULL);
}
