/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 06:57:29 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/03/29 20:37:33 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (d)
		return (ft_strcpy(d, s));
	return (0);
}
