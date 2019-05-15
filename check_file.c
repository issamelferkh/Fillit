/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 21:57:19 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/15 02:10:48 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			ft_check(int fd, int *count_b)
{
	char	buff[BUFF_SIZE_FILLIT + 1];
	int		r;
	int		i;

	while ((r = read(fd, buff, BUFF_SIZE_FILLIT)) > 0) // >= 1
	{
		i = 0;
		buff[r] = '\0';
		while (i < 20)
		{
			if ((i == 4 || i == 9 || i == 14 || i == 19)
					&& buff[i] != '\n') // verif if les \n inevery line (....\n)
				return (0);
			if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n') // verif if char '.' '#' '\n' | why buff[i] != '\n' ? 
				return (0);
			i++;
		}
		(*count_b)++;
		r = read(fd, buff, 1);
		if (r == 1 && buff[0] != '\n')
			return (0);
	}
	if (buff[0] == '\n')
		return (0);
	return (1);
}

int			ft_max_min(int fd, int *rcount)
{
	int		res;
	int		count;

	count = 0;
	res = ft_check(fd, &count);
	if (count < 1 || count > 26)
		return (0);
	(*rcount) = count;
	return (res);
}

int			ft_validate_tetris(char **tet, int *pound)
{
	int		ind[3];

	ind[2] = 0;
	ind[0] = 0;
	while (tet[ind[0]])
	{
		ind[1] = 0;
		while (tet[ind[1]])
		{
			if (tet[ind[0]][ind[1]] == '#' && ++(*pound))
			{
				if (ind[0] < 3 && tet[ind[0] + 1][ind[1]] == '#')
					ind[2] += 1;
				if (ind[0] > 0 && tet[ind[0] - 1][ind[1]] == '#')
					ind[2] += 1;
				if (ind[1] < 3 && tet[ind[0]][ind[1] + 1] == '#')
					ind[2] += 1;
				if (ind[1] > 0 && tet[ind[0]][ind[1] - 1] == '#')
					ind[2] += 1;
			}
			ind[1]++;
		}
		ind[0]++;
	}
	return (ind[2]);
}

char		**ft_read_tetriminos(char *buff)
{
	int		r;
	int		i[2];
	char	**block;

	block = (char**)malloc(sizeof(char*) * 5);
	block[4] = 0;
	i[0] = -1;
	r = 0;
	while (++i[0] < 4)
	{
		block[i[0]] = (char*)malloc(sizeof(char) * 5);
		i[1] = -1;
		while (++i[1] < 4)
		{
			if (buff[r] == '\n')
				r++;
			block[i[0]][i[1]] = buff[r++];
		}
		block[i[0]][i[1]] = '\0';
	}
	return (block);
}

int			ft_read(int fd)
{
	char	buff[BUFF_SIZE_FILLIT];
	int		count;
	int		pound;

	count = 0;
	while (read(fd, buff, BUFF_SIZE_FILLIT) >= 0)
	{
		pound = 0;
		count = ft_validate_tetris(ft_read_tetriminos(buff), &pound);
		if (pound > 4)
			return (0);
		if (count != 6 && count != 8)
			return (0);
		if (read(fd, buff, 1) == 0)
			break ;
	}
	return (1);
}