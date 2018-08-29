#include <stdio.h>
#include "bsq.h"

t_map	*ft_read_map(int	fd)
{
	int		n_read;
	int		n_buff;
	char	buff[BUFF_SIZE + 1];
	t_map	*map;

	map = malloc(sizeof(t_map));
	n_buff = -1;
	map->map = malloc(sizeof(char));
	map->map[0] = '\0';
	while ((n_read = read(fd, buff, BUFF_SIZE)) > 0 && ++n_buff > -1)
		map->map = ft_malloc(map->map, n_read, n_buff, buff);
	return (ft_check_map(map));
}

t_map	*ft_check_map(t_map *map)
{
	int i;
	int size_cons; // taille de la consigne;
	int cons_length;
	int nb_check;
	int	w;
	int	h;
	int	n_lines;
	t_obs *previous;
	t_obs *current;

	w = 0;
	h = 0;
	cons_length = 0;
	size_cons = 0;
	i = -1;
	nb_check = 0;
	n_lines = ft_atoi(map->map);
	map->obs = malloc(sizeof(t_obs*) * n_lines);
	current = NULL;
	previous = NULL;
	while(map->map[++i])
	{
		if (map->map[i] == map->c_full ||
					map->map[i] == map->c_obs || map->map[i] == map->c_empty || h == 0 || map->map[i] =='\n')
		{
			if (map->map[i] == '\n')
			{
				map->obs[h] = NULL;
				previous = NULL;
				h++;
				if (w == nb_check)
					nb_check = 0;
				else if (h > 2)
					return (NULL);
				continue ;
			}
			if (h > 0 && map->map[i] == map->c_obs)
			{
				current = malloc(sizeof(t_obs));
				current->x = (h == 1) ? w : nb_check;
				current->next = NULL;
				if (previous == NULL)
					map->obs[h - 1] = current;
				else
					previous->next = current;
				previous = current;
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
	if (n_lines == h - 1 && cons_length == 3)
	{
		map->h = n_lines;
		map->w = w;
		while (map->map[0] != '\n')
			map->map += 1;
		map->map += 1;
		return (map);
	}
	return (NULL);
}

char	*ft_malloc(char *map, int n_read, int n_buff, char *buff)
{
	char *new_map;

	new_map = malloc(sizeof(char) * (n_buff * BUFF_SIZE + n_read + 1));
	buff[n_read] = '\0';
	ft_strcpy(new_map, map);
	ft_strcat(new_map, buff);
	free(map);
	return (new_map);
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
			(map == NULL) ? write(1, "map error\n", 10) : ft_solve_map(map);
	}
	return (0);
}
