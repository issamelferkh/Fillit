/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 00:28:41 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/18 00:28:44 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void	ft_check_file(char *av, int *block_num)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) == -1 || !ft_check_block_num(fd, block_num))
	{
		ft_putstr("Invalid File\n");
		exit(-1); // why -1 && check if au
	}
	close(fd);
	
	if ((fd = open(av, O_RDONLY)) == -1 || !ft_read_valid_tetro(fd)) 
	{
		ft_putstr("error\n");
		exit(-1);
	}
	close(fd);
}

int main(int ac, char **av)
{
	int fd;
	int block_num;
	char	**output;
	t_point	**minos;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	block_num = 0;
	ft_check_file(av[1], &block_num);
	fd = open(av[1], O_RDONLY);
	minos = ft_position(fd, &block_num);
	close(fd);
	fd = open(av[1], O_RDONLY);
	output = create_output(ft_dim(block_num * 4));
	fillit_solve(minos, output, ft_dim(block_num * 4));
	return (0);
}
