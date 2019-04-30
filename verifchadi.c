/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:21:44 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/04/28 18:05:11 by iel-ferk         ###   ########.fr       */
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
	int fd1, fd2;
	int r1 = 1, r2;
	int i = 0;
	int flag = 1;
	char *line;
	char buff1[TETRO_SIZE + 1];
	char buff2[6];
	char **split;

//	if (ac == 2)
//	{
		fd1 = open(av[1],O_RDONLY);
		//fd2 = open(av[2],O_RDONLY);
		/*
		while (get_next_line(fd, &line))
		{
			printf("%s\n",line );
			//free(line);
		}
		//free(line);		*/

		// comparaison between input testfile 
		//	and a valid tetro
		//
		/*
		while ((r1 = read(fd1, buff1, 4)) && (r2 = read(fd2, buff2, 4)) && i < 5)
		{
			buff1[r1] = '\0';
			buff2[r2] = '\0';
			
			if(ft_strcmp(buff1, buff2) != 0)
				flag  = 0;
			i++;
		}
		*/
		// verification of '#' and '.'
		//
		while ((r1 = read(fd1, buff1,TETRO_SIZE)) > 0)
		{
			buff1[r1] = '\0';
			split = ft_strsplit(buff1, '\n');
			i = -1;
			while (split[++i])
				if (!ft_char_validity(split[i]))
					break;
			if (i != 4)
			{
				flag = 3;
				break;
			}
			if (!(r1 = read(fd1, buff1, 1)))
				break;
			buff1[r1] = '\0';
		}
		if (flag == 1)
			printf("Is a valid File\n");
		else if (flag == 3)
			printf("Not a valid file\n");
		else
			printf("Is not a Titro\n");
		if (close(fd1) == -1)
			printf("close error");
	return (0);
}
