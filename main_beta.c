#include "libft/libft.h"
#include "fillit.h"

void	ft_check_file(char *av, int *block_num)
{
	int fd;

	if ((fd = open(av, O_RDONLY)) == -1 || !ft_check_block_num(fd, block_num))
	{
		ft_putstr("Invalid File\n");
		exit(-1);
	}
	else
		ft_putstr("The File Is Valid\n");
	close(fd);
	if ((fd = open(av, O_RDONLY)) == -1 || !ft_read(fd))
	{
		ft_putstr("error\n");
		exit(-1);
	}
	else
		ft_putstr("The File Is Valid\n");
	close(fd);
}

int main(int ac, char **av)
{
	int block_num;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	block_num = 0;
	ft_check_file(av[1], &block_num);
	
	return (0);
}
