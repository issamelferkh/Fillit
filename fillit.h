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
# define BUFF_SIZE_FILLIT 20
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

void			ft_check_file(char *av, int *block_num); // void error(char *av, int *rcount);
int				ft_check_block_num(int fd, int *block_num); // int ft_max_min(int fd, int *rcount);
int				ft_check_block_valid(int fd, int *block_num); // int ft_check(int fd, int *count_b);
int				ft_read_valid_tetro(int fd); //int ft_read(int fd);
char			**ft_read_tetro(char *buff); // char **ft_read_tetriminos(char *buff);
int				ft_valid_tetro(char **tetro, int *sharp); // int ft_validate_tetris(char **tet, int *pound);
t_point			**ft_position(int fd, int *block_num); //t_point **ft_coord(int fd, int *rcount);
void			ft_position_block(char **block, t_point **position, int *count); //void minos_coord(char **block, t_point **coord, int *count);
char			**ft_read_block(int fd);



int				ft_dim(int dim); // int				sqrt_sup(int n);
int				is_safe(char **output, t_point *tetrisa, int a, int b); // int				is_safe(char **grid, t_point *tetrisa, int a, int b);
void			remove_minos(char **output, t_point *tetrisa); // void			remove_minos(char **grid, t_point *tetrisa);
void			place_minos(char **output, t_point *tetrisa, int i, int j); // void			place_minos(char **grid, t_point *tetrisa, int i, int j);
char			**create_output(int dim); // char			**create_grid(int dim);
void			ft_check_file(char *av, int *block_num); // void			ft_check_file(char *av, int *block_num);
void			print_output(char	**output); // void			print_grid(char	**grid);
int				recursion(t_point **coord, char **output, int i, int j); // int				recursion(t_point **coord, char **grid, int i, int j);
void			free_output(char **output, int dim); // void			free_grid(char **grid, int dim);
void			fillit_solve(t_point **coord, char **output, int dim); // void			fillit_solve(t_point **coord, char **grid, int dim);

#endif
