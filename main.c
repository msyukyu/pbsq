
#include <stdio.h> // a retirer

#include "bsq.h"

t_map	*ft_read_map(int	fd)
{
	int ret;
	int i;
	char buff[BUFF_SIZE];
	t_map *map;

	map = malloc(sizeof(t_map));
	i = -1;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 && ++i > -1)
		map->map = ft_malloc(map->map, ret, i, buff);

	printf("%s\n", map->map); // test
	return (ft_check_map (map, 0, 0));
}

t_map	*ft_check_map(t_map *map, int w, int h)
{
	int i;
	int size_cons; // taille de la consigne;
	int cons_length;
	int nb_check;
	
	cons_length = 0;
	size_cons = 0;
	i = -1;
	nb_check = 0;
	while(map->map[++i])
	{
		if (map->map[i] == '\n')
		{
			h++;
			if (w == nb_check)
				nb_check = 0;
		}
		if (h == 1)
			w++;
		else if (h != 0)
			nb_check++;
		if (h == 0)
		{
			size_cons++;
			if (map->map[i] <= '9' && map->map[i] >= '0')
				cons_length++;
			else
			{

				cons_length++;
			}
		}	
	}
	nb_check = ft_atoi(map->map);
	if (nb_check == h - 1)
		return (map);
	return (NULL);
}

int		ft_atoi(char *str)
{
	int i;
	int resultat;
	int signe;

	signe = 1;
	i = 0;
	resultat = 0;
	while (str[i] == ' ' || (str[i] == '+' &&
				(str[i + 1] > 47 && str[i + 1] < 58)))
		i++;
	if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
	{
		signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + str[i] - '0';
		i++;
	}
	return (signe * resultat);
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
	int		fd;

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
