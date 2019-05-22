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

#include "fillit.h"

int			is_safe(char **output, t_point *minos, int i, int j)
{
	int		index;
	int		dim;

	dim = 0;
	while (output[0][dim])
		dim++;
	index = 1;
	if (output[i][j] != '.')
		return (0);
	while (index < 4)
	{
		if ((minos[index].x + j) >= 0 && (minos[index].x + j) < dim
				&& (minos[index].y + i) < dim)
		{
			if (output[minos[index].y + i][minos[index].x + j] != '.')
				return (0);
		}
		else
			return (0);
		index++;
	}
	return (1);
}

void		place_minos(char **output, t_point *minos, int i, int j)
{
	int		ind;

	ind = 0;
	while (ind < 4)
	{
		output[minos[ind].y + i][minos[ind].x + j] = (minos[0].index + 65);
		ind++;
	}
	minos[4].x = j;
	minos[4].y = i;
}

void		remove_minos(char **output, t_point *minos)
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
			if (output[i][j] == (minos[0].index + 65))
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

int			ft_solution(char **output, t_point **minos, int i, int j)
{
	if (!*minos)
		return (1);
	while (output[i])
	{
		while (output[i][j])
		{
			if (is_safe(output, *minos, i, j) == 1)
			{
				place_minos(output, *minos, i, j);
				if (ft_solution(output, minos + 1, 0, 0) == 1)
					return (1);
				else
					remove_minos(output, *minos);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void		fillit_solve(char **output, t_point **minos, int dim)
{
	int		l;

	l = 0;
	while (!(ft_solution(output, minos, 0, 0)))
	{
		free_output(output, dim);
		l++;
		output = create_output(dim + l);
	}
	print_output(output);
}