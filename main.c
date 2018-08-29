#include "bsq.h"

t_map	*ft_read_map(int fd)
{
	t_segmap	*previous;
	t_segmap	*current;
	t_map		*map;
	int			n_read;

	previous = NULL;
	map = malloc(sizeof(t_map));
	map->segmap = malloc(sizeof(t_segmap*));
	map->n_buff = 0;
	current = malloc(sizeof(t_segmap));
	current->seg = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((n_read = read(fd, current->seg, BUFF_SIZE)) > 0 && ++(map->n_buff))
	{
		current->seg[n_read] = '\0';
		current->next = NULL;
		if (previous == NULL)
			map->segmap = current;
		else
			previous->next = current;
		previous = current;
		current = malloc(sizeof(t_segmap));
		current->seg = malloc(sizeof(char) * (BUFF_SIZE + 1));
	}
	return (ft_check_map(map));
}

void	test_print_map(t_map *map)
{
	t_segmap	*current;

	current = map->segmap;
	while (current != NULL)
	{
		write(1, current->seg, 4096);
		current = current->next;
	}
}

void	ft_fill_map(t_square *best_square, t_map *map, char *final_map)
{
	int		x;
	int		y;

	while (*final_map != '\n')
		final_map++;
	final_map++;
	y = best_square->ys - 1;
	while (++y < best_square->ys + best_square->side)
	{
		x = best_square->xs - 1;
		while (++x < best_square->xs + best_square->side)
		{
			final_map[y * (map->w + 1) + x] = map->c_full;
		}
	}
	write(1, final_map, (map->w + 1) * map->h);
}

void	ft_print_filled_map(t_square *best_square, t_map *map)
{
	char		*final_map;
	t_segmap	*current;

	if (best_square == NULL)
	{
		write(1, "map error\n", 10);
		return ;
	}
	final_map = malloc(map->n_buff * BUFF_SIZE * sizeof(char) + 1);
	final_map[0] = '\0';
	current = map->segmap;
	while (current != NULL)
	{
		ft_strcat(final_map, current->seg);
		current = current->next;
	}
	ft_fill_map(best_square, map, final_map);
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
			(map == NULL) ? write(2, "map error\n", 10) : ft_solve_map(map);
	}
	return (0);
}
