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

// fonction to verify if 'str' is filled by # and .
// returns 1 or 0 

int		ft_char_validity(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i])
	{
		if (str[i] != '#' && str[i] != '.')
			return (0);
		i++;
	}
	printf("***** char validity ****** ASCII STR[i] = %d\n", str[i]);
	return ((str[i]) ? 1 : 0);
}

// function checks the validity of "ONE" tetro
//	with char validity , allocates the memory and 
// stores the tetro if its Valid else returns NULL

char 	*ft_check_tetro(int *fd)
{
	char buf[5];
	int ret;
	int i;
	char *tetro;
	char *tmp;
	int fd1;

	if (!(tetro = ft_strnew(0)))
		return (0);
	printf("************** Check Tetro *****************\n");
	i = -1;
	printf("FD = %d\n",fd1);
	while (++i < 4 && (ret = read(f*d1, buf, 5)) > 0)
		{
			buf[ret] = '\0';
			tmp = tetro;
			//printf("*********\nTMP = %s\nBUF =%s\n*******\n",tmp, buf);
			if (!ft_char_validity(buf))
				return (0);
			tetro = ft_strjoin(tmp, buf);
			printf("Joining tetro %d time\nResult = %s\n", i, tetro);
			free(tmp);
			printf("RET = %d\n", ret);
		}
		printf("FD = %d\nRET = %d\n",fd1, ret);
		printf("*******************************************");
		return (tetro);
}

int main(int  ac, char **av)
{
	int fd1, fd2;
	int r1 = 1, r2;
	int i = 0;
	int flag = 1;
	char *line;
	char *tetro;
	char buff1[5];
	char buff2[5];

//	if (ac == 2)
//	{
		printf("Opening File...\n");
		fd1 = open(av[1],O_RDWR);
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
		printf("Comparing between input and testfile:\n");
		/*while ((r1 = read(fd1, buff1, 4)) && (r2 = read(fd2, buff2, 4)) && i < 5)
		{
			buff1[r1] = '\0';
			buff2[r2] = '\0';
			
			if(ft_strcmp(buff1, buff2) != 0)
				flag  = 0;
			i++;
		}*/

		// verification of '#' and '.'
		//	and file structure
		printf("Checking validity of Inputfile:\n");
		printf("first Tetro:\n");
		;
		printf("\nTETRO\n%s\n", tetro);
		/*r1 = read(fd1, buff1, 2);
		buff1 [r1] = '\0';
		printf("%s\n",buff1);*/
		tetro = ft_check_tetro(&fd1);
		printf("%s\n",tetro);
		/*
		while ((tetro = ft_check_tetro(&fd1)) && (r1 = read(fd1, buff1, 1)) > 0 && *buff1 == '\n')
		{
			printf("%s\n",tetro);
			free(tetro);
			tetro = ft_check_tetro(&fd1);
		}

		if (r1)
			printf("Error in Testfile");
		else
			printf("Test File is not Valid");
		if (flag)
			printf("Is a Titro\n");
		else
			printf("Is not a Titro\n");
//	}
//	else
//	{
//		printf("more than file !");
//	}*/
	return (0);
}
