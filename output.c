/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 00:22:42 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/21 00:22:45 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

char	**create_output(int dim)
{
	int 	i;
	int		j;
	char 	**output;

	i = 0;
	j = 0;
	if (!(output = (char **)malloc(sizeof(char *) * dim + 1)))
		return (NULL);
	while (i < dim)
	{
		if (!(output[i] = (char *)malloc(sizeof(char) * dim + 1)))
			return (NULL);
		j = 0;
		while (j < dim)
		{
			output[i][j] = '.';
			j++;
		}
		output[i][j] = '\0';
		i++;
	}
	output[i] = NULL; // wach darouri za3ma ? can I use 0 or \0 ? 
	return (output);
}

void	print_output(char **output)
{
	int		i;

	i = 0;
	while (output[i])
	{
		ft_putstr(output[i]);
		ft_putstr("\n");
		i++;
	}
}

void	free_output(char **output, int dim)
{
	int		i;

	i = 0;
	while (i < dim)
	{
		free(output[i]);
		i++;
	}
	free(output);
	output = NULL;
}

int		ft_dim(int dim)
{
	int		i;

	i = 0;
	while ((i * i) < dim)
		i++;
	return (i);
}
