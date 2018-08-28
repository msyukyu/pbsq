
#include <stdio.h>

#include "bsq.h"
char	*ft_strcat(char *dest, char *src)
void ft_strcpy(char *dest, char *src)


t_map	*ft_read_map(int	fd)
{
	int ret;
	int i;
	char buff[BUFF_SIZE];
	t_map *map;

	map = malloc(sizeof(t_map));
	i = -1;
	while (ret = read(fd, buff, BUFF_SIZE) > 0 && ++i > -1)
		map->map = ft_malloc(map->map, ret, i, buff);
	printf("%s\n", map->map);
	return (ft_check_map (map, 0, 0));
}

t_map	*ft_check_map(t_map *map, int x, int y)
{
	int i;
	int size_cons;

	size_cons = 0;
	i = -1;
	while(map->map[++i])
	{
		if (y == 0)
			size_cons++;
		if (map->map[i] == '\n')
			y++;
		if (y == 1)
			x++;
	}
}

void ft_strcpy(char *dest, char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
}

char *ft_malloc(char *str, int ret, int size, char *buff)
{
	char *tmp_str;

	tmp_str = malloc(sizeof(char) * (size * BUFF_SIZE + ret + 1));
	ft_strcpy(tmp_str, str);
	ft_strcat(tmp_str, buff);
	free (str);
	return (tmp_str);
}

int		main(int argc, char *argv[])
{
	t_map	*map;
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

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int i2;

	i = 0;
	i2 = 0;
	while (dest[i] != '\0')
		i++;
	while (src[i2] != '\0')
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}
