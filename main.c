
#include <stdio.h> // a retirer

#include "bsq.h"

t_map	*ft_read_map(int	fd)
{
	int n_read;
	int n_buff;
	char buff[BUFF_SIZE];
	t_map *map;

	map = malloc(sizeof(t_map));
	n_buff = -1;
	map->map = malloc(sizeof(char));
	map->map[0] = '\0';
	while ((n_read = read(fd, buff, BUFF_SIZE)) > 0 && ++n_buff > -1)
		map->map = ft_malloc(map->map, n_read, n_buff, buff);
	printf("%s\n", map->map); // test
	return (ft_check_map (map));
}

t_map	*ft_check_map(t_map *map)
{
	int i;
	int size_cons; // taille de la consigne;
	int cons_length;
	int nb_check;
	int	w;
	int	h;

	w = 0;
	h = 0;
	cons_length = 0;
	size_cons = 0;
	i = -1;
	nb_check = 0;
	while(map->map[++i])
	{
		if (map->map[i] == map->c_full ||
					map->map[i] == map->c_obs || map->map[i] == map->c_empty || h == 0 || map->map[i] =='\n')
		{
			if (map->map[i] == '\n')
			{
				h++;
				if (w == nb_check)
					nb_check = 0;
				else if (h > 2)
					return (NULL);
			}
			if (h == 1)
				w++;
			else if (h != 0)
				nb_check++;
			if (h == 0)
			{
				if (map->map[i] > '9' || map->map[i] < '0')
				{
					if (cons_length % 3 == 0)
						map->c_empty = map->map[i];
					else if (cons_length % 3 == 1)
						map->c_obs = map->map[i];
					else
						map->c_full = map->map[i];
					cons_length++;
					if (cons_length == 3 && (map->c_full == map->c_obs ||
								map->c_full == map->c_empty || map->c_obs == map->c_empty))
						return (NULL);
				}
			}
		}
		else
			return (NULL);
	}
	nb_check = ft_atoi(map->map);
	if (nb_check == h - 1 && cons_length == 3)
		return (map);
	return (NULL);
}

char *ft_malloc(char *str, int n_read, int n_buff, char *buff)
{
	char *tmp_str;

	tmp_str = malloc(sizeof(char) * (n_buff * BUFF_SIZE + n_read + 1));
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
				write(1, "map error\n", 10);
			else
			{
				write(1, "solvemap", 8);
				//	ft_solve_map(map);
			}
		}
	}
	return (0);
}
