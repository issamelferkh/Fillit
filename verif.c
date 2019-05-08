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

int main(int  ac, char **av)
{
	int fd1, fd2;
	int r1, r2;
	int i, j = 1, cpt = 0;
	int flag;
	char *line;
	char *titro;

//	if (ac == 2)
//	{
		
		/*
		while (get_next_line(fd, &line))
		{
			printf("%s\n",line );
			//free(line);
		}
		//free(line);		*/
		fd1 = open(av[1],O_RDONLY);
		printf("* Input file name: %s\n",av[1]);
		flag = 0;
		while (++cpt <= 19)
		{
			
			printf("* Titros file name: %s\n",ft_itoa(cpt));
			fd2 = open(ft_itoa(cpt),O_RDONLY);
			i = 0;
			printf("* i : %d\n",i);
			while (get_next_line(fd1, &line) && get_next_line(fd2, &titro) && i < 4)
			{
				if(ft_strcmp(line, titro) != 0)
					flag  = 1;
				i++;
				printf("### flag = %d\n",flag);
			}
			// i = 0;
			// //buff1 = {0,0,0,0,0};
			// r2 = 0;
			if (flag  == 0)
			{
				printf("+++ The Block %d is found in Titro %d +++\n", j,cpt);
				//break;
			}
			else
			{
				printf("!!! The Block %d is not found in Titro %d !!!\n", j,cpt);
			}
			//j = j + 5;
		}
		// if (flag != 0)
		// 	printf("Is not a Titro\n");

//	}
//	else
//	{
//		printf("more than file !");
//	}
	return (0);
}
