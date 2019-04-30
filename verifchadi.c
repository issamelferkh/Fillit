/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:21:44 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/30 13:23:03 by cjamal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_char_validity(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	return ((i == 4) ? 1 : 0);
}

int main(int  ac, char **av)
{
	int fd1;
	int r1 = 1;
	int i = 0;
	int flag = 1;
	char tmp[2]= "\n";
	char buff1[TETRO_SIZE + 1];
	char **split;

	fd1 = open(av[1],O_RDONLY);

	// function that verifies the structure of the FILE
	// 20 char/tetro + \n between two tetros 
	// 
	while ((tmp[0] == '\n') && (r1 = read(fd1, buff1, TETRO_SIZE)) > 0)
	{
		buff1[r1] = '\0';
		split = ft_strsplit(buff1, '\n');
		i = -1;
		//while (split[++i])
		//	if (!ft_char_validity(split[i]))
		//		break;
		
		while((split[++i]) && (ft_strlen(split[i]) == 4))
			;
		//printf("%d\n", i);
		if (i != 4)
		{
			flag = 3;
			break;
		}
		if (!(r1 = read(fd1, tmp, 1)))
			break;
		tmp[r1] = '\0';
	}
	if (flag == 1)
		printf("Is a valid File\n");
	else if (flag == 3 || (tmp[0] == '\n'))
		printf("Not a valid file\n");
	else
		printf("Is not a Titro\n");
	if (close(fd1) == -1)
		printf("close error");
	return (0);
}
