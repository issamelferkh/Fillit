/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:11:45 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/20 14:56:21 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned	int	ft_line_len(char *tab)
{
	unsigned int		i;

	i = 0;
	while (tab[i] != '\n' && tab[i] != '\0')
		i++;
	return (i);
}

static char				*ft_line_rest(char *tab)
{
	if (ft_strchr(tab, '\n'))
	{
		ft_strcpy(tab, ft_strchr(tab, '\n') + 1);
		return (tab);
	}
	if (ft_line_len(tab) > 0)
	{
		ft_strcpy(tab, ft_strchr(tab, '\0'));
		return (tab);
	}
	return (NULL);
}

int						get_next_line(int const fd, char **line)
{
	char				*tmp;
	char				buff[BUFF_SIZE + 1];
	static	char		*tab[4867];
	int					r;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	if (!(tab[fd]) && (tab[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while (!(ft_strchr(tab[fd], '\n')) && (r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strnjoin(tmp, buff, r);
		free(tmp);
	}
	*line = ft_strsub(tab[fd], 0, ft_line_len(tab[fd]));
	if (ft_line_rest(tab[fd]) == NULL)
		return (0);
	return (1);
}
