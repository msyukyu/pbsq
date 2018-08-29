#include <stdio.h>
#include "bsq.h"

t_map	*ft_read_map(int	fd)
{
	int		n_read;
	int		n_buff;
	char	buff[BUFF_SIZE + 1];
	t_map	*map;
	int 	n_lines;

	map = malloc(sizeof(t_map));
	n_buff = -1;
	map->map = malloc(sizeof(char));
	map->map[0] = '\0';
	while ((n_read = read(fd, buff, BUFF_SIZE)) > 0 && ++n_buff > -1)
		map->map = ft_malloc(map->map, n_read, n_buff, buff);
	n_lines = ft_atoi(map->map);
	map->obs = malloc(sizeof(t_obs*) * n_lines);
	if (!ft_check_map(map))
		return (NULL);
	while (map->map[0] != '\n')
		map->map += 1;
	map->map += 1;
	return (map);
}

void	ft_init_chain(t_map *map, t_obs *current, t_obs *previous, int var[2])
{
	if (map->h > 0 && map->map[var[0]] == map->c_obs)
	{
		current = malloc(sizeof(t_obs));
		current->x = (map->h == 1) ? map->w : var[1];
		current->next = NULL;
		if (previous == NULL)
			map->obs[map->h - 1] = current;
		else
			previous->next = current;
		previous = current;
	}
}

int		ft_check_map(t_map *map)
{
	int	var[2];
	int cons_length;
//	int n_lines;
	t_obs *previous;
	t_obs *current;

	map->w = 0;
	map->h = -1;
	cons_length = 0;
	var[0] = -1;
	var[1] = 0;
	map->obs = malloc(sizeof(t_obs*) * ft_atoi(map->map));
	current = NULL;
	previous = NULL;
	while(map->map[++var[0]])
	{
		//if (n_lines = ft_init_chain(map, previous, current , i) == 1)
		//	continue ;
		//else if (n_lines == 0)
		//	return (0);
		if (map->map[var[0]] == '\n')
		{
			map->h += 1;
			map->obs[map->h] = NULL;
			previous = NULL;
			if (map->w != var[1] && map->h > 1)
				return (0);
			var[1] = 0;
			continue ;
		}
		ft_init_chain(map, current, previous, var);
/*		if (map->h > 0 && map->map[i] == map->c_obs)
		{
			current = malloc(sizeof(t_obs));
			current->x = (map->h == 1) ? map->w : nb_check;
			current->next = NULL;
			if (previous == NULL)
				map->obs[map->h - 1] = current;
			else
				previous->next = current;
			previous = current;
		}*/
		map->w = (map->h == 0) ? map->w + 1: map->w;
		var[1] = (map->h != -1) ? var[1] + 1 : var[1];	
		if ((map->map[var[0]] > '9' || map->map[var[0]] < '0') && map->h == -1)
		{
			map->c_empty = (cons_length % 3 == 0) ? map->map[var[0]]: map->c_empty;
			map->c_obs = (cons_length % 3 == 1) ? map->map[var[0]]: map->c_obs;
			map->c_full = (cons_length % 3 == 2) ? map->map[var[0]]: map->c_full;
			if (++cons_length == 3 && (map->c_full == map->c_obs ||
						map->c_full == map->c_empty || map->c_obs == map->c_empty))
				return (0);
		}
		if (map->map[var[0]] != map->c_full &&
				map->map[var[0]] != map->c_obs &&
				map->map[var[0]] != map->c_empty && map->h != -1 && map->map[var[0]] !='\n')
			return (0);
	}
	return ((ft_atoi(map->map) == map->h && cons_length == 3) ? 1 : 0);
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
