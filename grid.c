/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 06:54:10 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/18 06:54:13 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

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
