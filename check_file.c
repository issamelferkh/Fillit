/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 00:28:11 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/18 00:28:14 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_block_valid(int fd, int *block_num) 
{
	char buff[BUFF_SIZE + 1];
	int r;
	int i;
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		i = 0;
		while (i < 20)
		{
			if ((i == 4 || i == 9 || i == 14 || i == 19) && buff[i] != '\n')
				return (0);
			if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
				return (0);
			i++;
		}
		(*block_num)++;
		r = read(fd, buff, 1);
		if (r == 1 && buff[0] != '\n')
			return (0);
	}
	if (buff[0] == '\n')
		return (0);
	return (1);
}

int		ft_check_block_num(int fd, int *block_num)
{
	int		flag;

	flag = ft_check_block_valid(fd, block_num);
	if (*block_num < 1 || *block_num > 26)
		return (0);
	return (flag); 
}

int			ft_valid_tetro(char **tetro, int *sharp) // count nbr of # and count nbr of relations in tetro
{
	int		i;
	int		j;
	int		relation;

	relation = 0;
	i = 0;
	while (tetro[i])
	{
		j = 0;
		while (tetro[j])
		{
			if (tetro[i][j] == '#' && ++(*sharp))
			{
				if (i < 3 && tetro[i + 1][j] == '#')
					relation++;
				if (i > 0 && tetro[i - 1][j] == '#')
					relation++;
				if (j < 3 && tetro[i][j + 1] == '#')
					relation++;
				if (j > 0 && tetro[i][j - 1] == '#')
					relation++;
			}
			j++;
		}
		i++;
	}
	return (relation);
}

char		**ft_read_tetro(char *buff) // read buff and stock it in **tetro
{
	int		r;
	int 	i;
	int		j;
	char	**tetro;

	tetro = (char**)malloc(sizeof(char*) * 5);
	tetro[4] = 0;
	r = 0;
	i = 0;
	while (i < 4)
	{
		tetro[i] = (char*)malloc(sizeof(char) * 5);
		j = 0;
		while (j < 4)
		{
			if (buff[r] == '\n')
				r++;
			tetro[i][j] = buff[r];
			j++;
			r++;
		}
		tetro[i][j] = '\0';
		i++;
	}
	return (tetro);
}

int			ft_read_valid_tetro(int fd) // valid nbr of # and relations => for valid a tetro
{
	char	buff[BUFF_SIZE];
	int		relation; // nbr relation
	int		sharp; // nbr of #

	relation = 0;
	while (read(fd, buff, BUFF_SIZE) > 0) // why = 0 ! && why not buff[r] = '\0'
	{
		sharp = 0;
		relation = ft_valid_tetro(ft_read_tetro(buff), &sharp);
		if (sharp > 4)
			return (0);
		if (relation != 6 && relation != 8)
			return (0);
		if (read(fd, buff, 1) == 0)
			break ;
	}
	return (1);
}
