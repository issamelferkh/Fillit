/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:58:07 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/05 01:44:04 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_intlen(int n)
{
	int			len;

	len = 2;
	if (n < 0)
		n = -n;
	while (n /= 10)
		len++;
	return (len);
}

static	void	ft_is_neg(int *n, int *sig)
{
	if (*n < 0)
	{
		*n *= -1;
		*sig = 1;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	int			sig;
	int			len;

	sig = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ft_is_neg(&n, &sig);
	len = ft_intlen(n) + sig;
	if ((str = (char *)malloc(sizeof(char) * len)) == 0)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	if (sig == 1)
	{
		str[0] = '-';
	}
	return (str);
}
