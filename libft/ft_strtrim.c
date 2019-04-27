/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 07:28:52 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/03 21:19:55 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_ws(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str && is_ws(*str))
		str++;
	i = ft_strlen(str);
	while (is_ws(str[i - 1]) && i > 0)
		i--;
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res = ft_strncpy(res, str, i);
	res[i] = '\0';
	return (res);
}
