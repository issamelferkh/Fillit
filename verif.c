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
	int str_len;
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != '#' || str[i] != '.')
			return (0);
		i++;
	}
	return ((str[i]) ? 1 : 0);
}
int main(int  ac, char **av)
{
	int fd1, fd2;
	int r1, r2;
	int i = 0;
	int flag = 1;
	char *line;
	char buff1[5];
	char buff2[5];

//	if (ac == 2)
//	{
		fd1 = open(av[1],O_RDONLY);
		fd2 = open(av[2],O_RDONLY);
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
		while ((r1 = read(fd1, buff1, 4)) && (r2 = read(fd2, buff2, 4)) && i < 5)
		{
			buff1[r1] = '\0';
			buff2[r2] = '\0';
			
			if(ft_strcmp(buff1, buff2) != 0)
				flag  = 0;
			i++;
		}
		// verification of '#' and '.'
		//
		/*while ((r1 = read(fd1, buff1, 4)))
		{
			buff1[r1] = '\0';
			if (!ft_char_validity(buff1))
				flag = 3;
		}*/
		if (flag)
			printf("Is a Titro\n");
		else
			printf("Is not a Titro\n");

//	}
//	else
//	{
//		printf("more than file !");
//	}
	return (0);
}
