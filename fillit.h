/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 00:26:26 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/21 00:26:28 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 20
# include <unistd.h> // I think is in libft.h !!!
# include <stdlib.h> // I think is in libft.h !!!
# include <stdio.h> // I think is in libft.h !!!
# include <fcntl.h> // I think is in libft.h !!!

typedef struct	s_point
{
	int			x;
	int			y;
	int			index;
}				t_point;

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_check_file(char *av, int *block_num);
int				ft_check_block_num(int fd, int *block_num);
int				ft_check_block_valid(int fd, int *block_num);
int				ft_read_valid_tetro(int fd);
char			**ft_read_tetro(char *buff);
int				ft_valid_tetro(char **tetro, int *sharp);
t_point			**ft_position(int fd, int *block_num);
void			ft_position_block(char **block, t_point **position, int *count);
char			**ft_read_block(int fd);
char			**create_output(int dim);
int				ft_dim(int dim);
void			print_output(char **output);
void			free_output(char **output, int dim);
int				is_safe(char **output, t_point *minos, int i, int j);
void			remove_minos(char **output, t_point *minos);
void			place_minos(char **output, t_point *minos, int i, int j);
int				ft_solution(char **output, t_point **minos, int i, int j);
void			fillit_solve(char **output, t_point **minos, int dim);


#endif
