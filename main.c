
#include "bsq.h"

t_map	ft_read_map(int	fd)
{
	int ret;
	int i;
	char buff[BUFF_SIZE];
	t_map map;

	i = -1;
	while (ret = read(FD, buff, BUFF_SIZE) > 0 && ++i > -1)
		map.map = ft_malloc(map.map, ret, i);
}

char *ft_malloc(char *str, int ret, int size)
{
	char *tmp_str;

	tmp_str = malloc(sizeof(char) * (size * BUFF_SIZE + ret));	
}

void str_cpy(char *dest, char *src)
{

	while (*dest)
		*dest = *src;
}

int		main(int argc, char *argv[])
{
	t_map	map;
	int		i;

	map = NULL;
	i = -1;
	while (++i < argc)
	{
		if (argc == 1)
			map = ft_read_map(0);
		else if (i > 0)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd > 0)
				map = ft_read_map(fd);
			else
				map = NULL;
		}
		if (argc == 1 || i > 0)
		{
			if (map == NULL)
				ft_putstr("map error\n");
			else
				ft_solve_map(map);
		}
	}
	return (0);
}
