/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 04:04:58 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/12 04:04:59 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** *
=> check_file.c 
* ************************************************************************** */

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

/* ************************************************************************** *
=> ft_coord.c
* ************************************************************************** */

char		**ft_read_block(int fd)
{
	int		ind[3];
	char	buff[BUFF_SIZE_FILLIT];
	char	**block;

	block = (char**)malloc(sizeof(char*) * 5);
	block[4] = 0;
	if (!read(fd, buff, BUFF_SIZE_FILLIT))
		return (NULL);
	ind[0] = 0;
	ind[2] = 0;
	while (ind[0] < 4)
	{
		block[ind[0]] = (char*)malloc(sizeof(char) * 5);
		ind[1] = 0;
		while (ind[1] < 4)
		{
			if (buff[ind[2]] == '\n')
				ind[2]++;
			block[ind[0]][ind[1]++] = buff[ind[2]++];
		}
		block[ind[0]++][ind[1]] = '\0';
	}
	read(fd, buff, 1);
	return (block);
}

void		minos_coord(char **block, t_point **coord, int *count)
{
	int		ind[4];
	int		ref[2];

	ind[2] = 0;
	ind[0] = -1;
	ind[3] = 0;
	while (block[++ind[0]])
	{
		ind[1] = -1;
		while (block[ind[0]][++ind[1]])
		{
			if (block[ind[0]][ind[1]] == '#' && ind[2] == 0)
			{
				ind[2] = 1;
				ref[0] = ind[0];
				ref[1] = ind[1];
			}
			if (block[ind[0]][ind[1]] == '#')
			{
				coord[(*count) - 1][ind[3]].x = ind[1] - ref[1];
				coord[(*count) - 1][ind[3]].y = ind[0] - ref[0];
				coord[(*count) - 1][ind[3]++].index = (*count) - 1;
			}
		}
	}
}

t_point		**ft_coord(int fd, int *rcount)
{
	int		i;
	int		count;
	char	**block;
	t_point	**coord;

	coord = (t_point**)malloc(sizeof(t_point*) * (*rcount + 1));
	i = -1;
	while (++i < (*rcount))
		coord[i] = (t_point*)malloc(sizeof(t_point) * 5);
	count = 0;
	while ((block = ft_read_block(fd)) != NULL)
	{
		count++;
		minos_coord(block, coord, &count);
	}
	coord[count] = NULL;
	return (coord);
}

/* ************************************************************************** *
=> grid.c
* ************************************************************************** */

char	**create_grid(int dim)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	j = 0;
	if (!(grid = (char**)malloc(sizeof(char*) * dim + 1)))
		return (NULL);
	while (i < dim)
	{
		if (!(grid[i] = (char*)malloc(sizeof(char) * (dim + 1))))
			return (NULL);
		j = 0;
		while (j < dim)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

void	print_grid(char **grid)
{
	int		i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i]);
		ft_putstr("\n");
		i++;
	}
}

void	free_grid(char **grid, int dim)
{
	int		i;

	i = 0;
	while (i < dim)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

int		sqrt_sup(int n)
{
	int		i;

	i = 0;
	while ((i * i) < n)
		i++;
	return (i);
}

/* ************************************************************************** *
=> read_file.c
* ************************************************************************** */

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

/* ************************************************************************** *
=> solve.c
* ************************************************************************** */

int			is_safe(char **grid, t_point *tetrisa, int a, int b)
{
	int		index;
	int		dim;

	dim = 0;
	while (grid[0][dim])
		dim++;
	index = 1;
	if (grid[a][b] != '.')
		return (0);
	while (index < 4)
	{
		if ((tetrisa[index].x + b) >= 0 && (tetrisa[index].x + b) < dim
				&& (tetrisa[index].y + a) < dim)
		{
			if (grid[tetrisa[index].y + a][tetrisa[index].x + b] != '.')
				return (0);
		}
		else
			return (0);
		index++;
	}
	return (1);
}

void		place_minos(char **grid, t_point *tetrisa, int i, int j)
{
	int		ind;

	ind = 0;
	while (ind < 4)
	{
		grid[tetrisa[ind].y + i][tetrisa[ind].x + j] = (tetrisa[0].index + 65);
		ind++;
	}
	tetrisa[4].x = j;
	tetrisa[4].y = i;
}

void	remove_minos(char **grid, t_point *tetrisa)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == (tetrisa[0].index + 65))
			{
				grid[i][j] = '.';
				count++;
			}
			j++;
			if (count == 4)
				return ;
		}
		i++;
	}
}

int			recursion(t_point **tetrisa, char **grid, int i, int j)
{
	if (!*tetrisa)
		return (1);
	while (grid[i])
	{
		while (grid[i][j])
		{
			if (is_safe(grid, *tetrisa, i, j) == 1)
			{
				place_minos(grid, *tetrisa, i, j);
				if (recursion(tetrisa + 1, grid, 0, 0) == 1)
					return (1);
				else
					remove_minos(grid, *tetrisa);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void		fillit_solve(t_point **coord, char **grid, int dim)
{
	int		l;

	l = 0;
	while (!(recursion(coord, grid, 0, 0)))
	{
		free_grid(grid, dim);
		l++;
		grid = create_grid(dim + l);
	}
	print_grid(grid);
}

/* ************************************************************************** *
=> main.c
* ************************************************************************** */
// check error 
void		error(char *av, int *rcount)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1 || !ft_max_min(fd, rcount)) // check open + ft_max_min ?
	{
		ft_putstr("error\n");
		exit(-1);
	}
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1 || !ft_read(fd)) // check open + ft_read ?
	{
		ft_putstr("error\n");
		exit(-1);
	}
	close(fd);
}

int			main(int ac, char **av) // ok
{
	int		fd; // ok
	int		num_block; // ok
	char	**grid; // ?
	t_point	**coord; // ?

	num_block = 0; // ok
	if (ac != 2) // ok
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (1);
	}
	error(av[1], &num_block); // check error ? => 6 ft
	fd = open(av[1], O_RDONLY);
	coord = ft_coord(fd, &num_block);
	close(fd);
	fd = open(av[1], O_RDONLY);
	grid = create_grid(sqrt_sup(num_block * 4));
	fillit_solve(coord, grid, sqrt_sup(num_block * 4));
	return (0);
}

