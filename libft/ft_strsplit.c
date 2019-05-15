/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:42:02 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/07 21:48:22 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_str_nbr(char *str, char c)
{
	int	nbr;
	int flag;
	int i;

	nbr = 0;
	flag = 0;
	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			flag = 0;
		else
		{
			if (flag == 0)
				nbr++;
			flag = 1;
		}
		i++;
	}
	return (nbr);
}

static	char	*ft_cat_word(char *str, int *n, char c)
{
	char		*word;
	int			i;
	int			i_first;
	int			i_last;

	i = *n;
	while (str[i] && str[i] == c)
		i++;
	i_first = i;
	while (str[i] && str[i] != c)
		i++;
	i_last = i;
	*n = i;
	if ((word = (char*)malloc(sizeof(char) * i_last - i_first)) == 0)
		return (NULL);
	i = 0;
	while (i_first < i_last)
	{
		word[i] = str[i_first];
		i_first++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(const char *str, char c)
{
	char	**res;
	int		j;
	int		i;

	if (str == NULL)
		return (NULL);
	res = (char**)malloc(sizeof(char*) * ft_str_nbr((char *)str, c) + 1);
	if (res == 0)
		return (NULL);
	j = 0;
	i = 0;
	while (j < ft_str_nbr((char *)str, c))
	{
		res[j] = ft_cat_word((char *)str, &i, c);
		j++;
	}
	res[j] = 0;
	return (res);
}
