/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 06:56:14 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/18 06:56:21 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

int			is_safe(char **output, t_point *tetrisa, int a, int b)
{
	int		index;
	int		dim;

	dim = 0;
	while (output[0][dim])
		dim++;
	index = 1;
	if (output[a][b] != '.')
		return (0);
	while (index < 4)
	{
		if ((tetrisa[index].x + b) >= 0 && (tetrisa[index].x + b) < dim
				&& (tetrisa[index].y + a) < dim)
		{
			if (output[tetrisa[index].y + a][tetrisa[index].x + b] != '.')
				return (0);
		}
		else
			return (0);
		index++;
	}
	return (1);
}

void		place_minos(char **output, t_point *tetrisa, int i, int j)
{
	int		ind;

	ind = 0;
	while (ind < 4)
	{
		output[tetrisa[ind].y + i][tetrisa[ind].x + j] = (tetrisa[0].index + 65);
		ind++;
	}
	tetrisa[4].x = j;
	tetrisa[4].y = i;
}

void	remove_minos(char **output, t_point *tetrisa)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (output[i])
	{
		j = 0;
		while (output[i][j])
		{
			if (output[i][j] == (tetrisa[0].index + 65))
			{
				output[i][j] = '.';
				count++;
			}
			j++;
			if (count == 4)
				return ;
		}
		i++;
	}
}

int			recursion(t_point **tetrisa, char **output, int i, int j)
{
	if (!*tetrisa)
		return (1);
	while (output[i])
	{
		while (output[i][j])
		{
			if (is_safe(output, *tetrisa, i, j) == 1)
			{
				place_minos(output, *tetrisa, i, j);
				if (recursion(tetrisa + 1, output, 0, 0) == 1)
					return (1);
				else
					remove_minos(output, *tetrisa);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void		fillit_solve(t_point **position, char **output, int dim)
{
	int		l;

	l = 0;
	while (!(recursion(position, output, 0, 0)))
	{
		free_output(output, dim);
		l++;
		output = create_output(dim + l);
	}
	print_output(output);
}