/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 00:26:48 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/18 00:29:00 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_read_block(int fd)
{
	int		i[3];
	char	buff[BUFF_SIZE];
	char	**block;

	block = (char**)malloc(sizeof(char*) * 5);
	block[4] = 0;
	if (!read(fd, buff, BUFF_SIZE))
		return (NULL);
	i[0] = 0;
	i[2] = 0;
	while (i[0] < 4)
	{
		block[i[0]] = (char*)malloc(sizeof(char) * 5);
		i[1] = 0;
		while (i[1] < 4)
		{
			if (buff[i[2]] == '\n')
				i[2]++;
			block[i[0]][i[1]++] = buff[i[2]++];
		}
		block[i[0]++][i[1]] = '\0';
	}
	read(fd, buff, 1);
	return (block);
}

void		ft_position_block(char **block, t_point **position, int *count)
{
	int		i, j, flag, p;
	int		X, Y;

	flag = 0;
	j = -1;
	p = 0;
	while (block[++j])
	{
		i = -1;
		while (block[j][++i])
		{
			if (block[j][i] == '#' && flag == 0)
			{
				flag = 1;
				Y = j;
				X = i;
			}
			if (block[j][i] == '#')
			{
				position[(*count) - 1][p].x = i - X;
				position[(*count) - 1][p].y = j - Y;
				position[(*count) - 1][p].index = (*count) - 1;
				p++;
			}
		}
	}
}

// void		ft_position_block(char **block, t_point **position, int *count)
// {
// 	int		i[4];
// 	int		ref[2];

// 	i[2] = 0;
// 	i[0] = -1;
// 	i[3] = 0;
// 	while (block[++i[0]])
// 	{
// 		i[1] = -1;
// 		while (block[i[0]][++i[1]])
// 		{
// 			if (block[i[0]][i[1]] == '#' && i[2] == 0)
// 			{
// 				i[2] = 1;
// 				ref[0] = i[0];
// 				ref[1] = i[1];
// 			}
// 			if (block[i[0]][i[1]] == '#')
// 			{
// 				position[(*count) - 1][i[3]].x = i[1] - ref[1];
// 				position[(*count) - 1][i[3]].y = i[0] - ref[0];
// 				position[(*count) - 1][i[3]++].index = (*count) - 1;
// 			}
// 		}
// 	}   
// }

t_point		**ft_position(int fd, int *block_num)
{
	int		i;
	int		count;
	char	**block;
	t_point	**position;

	position = (t_point**)malloc(sizeof(t_point*) * (*block_num + 1));
	i = -1;
	while (++i < (*block_num))
		position[i] = (t_point*)malloc(sizeof(t_point) * 5);
	count = 0;
	while ((block = ft_read_block(fd)) != NULL)
	{
		count++;
		ft_position_block(block, position, &count);
	}
	position[count] = NULL;
	return (position);
}
