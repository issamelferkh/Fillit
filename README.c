Planning
--------
File Validation => 16/05/2019
	ft_check_block_num	-> ok
	ft_read 			-> 1337: 20h -> 00h

Vendredi -> Dimanche
	all fillit


check_file.c -> for check validity of an input file.
main.c -> main + ft_check_file fonction
fillic.c -> all the code
fillit.h -> head

void			error(char *av, int *rcount);
{
	int				ft_max_min(int fd, int *rcount);
	{
		check nbr of blocks => (count < 1 || count > 26)
		int				ft_check(int fd, int *count_b); -> NULL
		{
			check validity chars of block => ('.','#','\n')
		}
	}
	int				ft_read(int fd);
	{
		int				ft_validate_tetris(char **tet, int *pound); -> NULL
		{
			check validity of titros => count relations => (pound > 4) && (count != 6 && count != 8) -> return (0)
		}
		char			**ft_read_tetriminos(char *buff); -> NULL
		{
			read titros -> char **block
		}
	}
}

t_point			**ft_coord(int fd, int *rcount);
{
	char			**ft_read_block(int fd);
	{
		NULL
	}
	void			minos_coord(char **block, t_point **coord, int *count);
	{
		NULL
	}
}

int				sqrt_sup(int n);
{
	NULL
}

void			fillit_solve(t_point **coord, char **grid, int dim);
{
	int				recursion(t_point **coord, char **grid, int i, int j);
	{
		int				is_safe(char **grid, t_point *tetrisa, int a, int b); -> NULL
		void			place_minos(char **grid, t_point *tetrisa, int i, int j); -> NULL
		void			remove_minos(char **grid, t_point *tetrisa); -> NULL
	}
	void			free_grid(char **grid, int dim); -> NULL
	char			**create_grid(int dim); -> NULL
	void			print_grid(char	**grid); -> NULL
}

