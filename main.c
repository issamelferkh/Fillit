/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 21:57:33 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/14 21:57:36 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

void		ft_check_file(char *av, int *block_num)
{
	int		fd;
	int		check_valid;

	check_valid = 0;
	if ((fd = open(av, O_RDONLY)) == -1 || !ft_max_min(fd, rcount)) // check open + ft_max_min ?
	{
		ft_putstr("error\n");
		exit(-1);
	}
	else
		check_valid++;
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1 || !ft_read(fd)) // check open + ft_read ?
	{
		ft_putstr("error\n");
		exit(-1);
	}
	else
		check_valid++;
	close(fd);
	if (check_valid != 0)
		ft_putstr("Valide file\n");
}

int			main(int ac, char **av) // ok
{
	int		fd; // ok
	int		block_num; // ok

	char	**grid; // ?
	t_point	**coord; // ?

	block_num = 0; // ok
	if (ac != 2) // ok
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	ft_check_file(av[1], &block_num); // check error ? => 6 ft
	// fd = open(av[1], O_RDONLY);
	// coord = ft_coord(fd, &num_block);
	// close(fd);
	// fd = open(av[1], O_RDONLY);
	// grid = create_grid(sqrt_sup(num_block * 4));
	// fillit_solve(coord, grid, sqrt_sup(num_block * 4));
	return (0);
}

