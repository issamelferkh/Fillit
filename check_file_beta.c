#include "libft/libft.h"
#include "fillit.h"

int		ft_check_block_valid(int fd, int *block_num)
{
	char buff[BUFF_SIZE_FILLIT + 1];
	int r;
	int i;
	while ((r = read(fd, buff, BUFF_SIZE_FILLIT)) > 0)
	{
		buff[r] = '\0';
		i = 0;
		while (i < 20)
		{
			if ((i == 4 || i == 9 || i == 14 || i == 19) && buff[i] != '\n')
				return (0);
			if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
				return (0);
			i++;
		}
		(*block_num)++;
		r = read(fd, buff, 1);
		if (r == 1 && buff[0] != '\n')
			return (0);
	}
	if (buff[0] == '\n')
		return (0);
	return (1);
}

int		ft_check_block_num(int fd, int *block_num)
{
	int		flag;

	flag = ft_check_block_valid(fd, block_num);
	if (*block_num < 1 || *block_num > 26)
		return (0);
	return (flag); 
}