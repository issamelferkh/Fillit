/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-ferk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 02:45:25 by iel-ferk          #+#    #+#             */
/*   Updated: 2019/05/12 02:45:26 by iel-ferk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE_FILLIT 20
# include <unistd.h> // I think is in libft.h !!!
# include <stdlib.h> // I think is in libft.h !!!
# include <fcntl.h> // I think is in libft.h !!!

typedef struct	s_point
{
	int			x;
	int			y;
	int			index;
}				t_point;

int				is_safe(char **grid, t_point *tetrisa, int a, int b);
void			remove_minos(char **grid, t_point *tetrisa);
void			place_minos(char **grid, t_point *tetrisa, int i, int j);
char			**create_grid(int dim);
int				ft_validate_tetris(char **tet, int *pound);
char			**ft_read_tetriminos(char *buff);
int				ft_check(int fd, int *count_b);
char			**ft_read_block(int fd);
t_point			**ft_coord(int fd, int *rcount);
int				ft_max_min(int fd, int *rcount);
int				ft_read(int fd);
void			ft_check_file(char *av, int *block_num);
void			print_grid(char	**grid);
int				recursion(t_point **coord, char **grid, int i, int j);
int				sqrt_sup(int n);
void			free_grid(char **grid, int dim);
void			fillit_solve(t_point **coord, char **grid, int dim);
void			minos_coord(char **block, t_point **coord, int *count);

#endif
