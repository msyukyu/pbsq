#include "bsq.h"

int			ft_find_x_obs(t_square *square, t_map *map)
{
	int		y;
	t_obs	*obs;
	int		x_max;

	x_max = -1;
	y = square->ys - 1;
	while (++y < square->ys + square->side)
	{
		obs = map->obs[y];
		while (obs != NULL)
		{
			if (square->xs + square->side - 1 < obs->x)
				break ;
			else if (obs->x >= square->xs && obs->x > x_max)
			{
				x_max = obs->x;
			}
			obs = obs->next;
		}
	}
	return (x_max);
}

t_square	*ft_init_square(void)
{
	t_square *square;

	square = malloc(sizeof(t_square));
	if (square == NULL)
		return (NULL);
	square->xs = 0;
	square->ys = 0;
	square->side = 1;
	return (square);
}

t_square	*ft_copy_square(t_square *square)
{
	t_square *new_square;

	new_square = malloc(sizeof(t_square));
	if (new_square == NULL)
		return (NULL);
	new_square->xs = square->xs;
	new_square->ys = square->ys;
	new_square->side = square->side;
	return (new_square);
}

void		ft_print_filled_map(t_square *best_square, t_map *map)
{
	int			x;
	int			y;

	if (best_square == NULL)
	{
		write(1, "map error\n", 10);
		return ;
	}
	y = best_square->ys - 1;
	while (++y < best_square->ys + best_square->side)
	{
		x = best_square->xs - 1;
		while (++x < best_square->xs + best_square->side)
		{
			map->map[y * (map->w + 1) + x] = map->c_full;
		}
	}
	write(1, map->map, (map->w + 1) * map->h);
}

void		ft_solve_map(t_map *map)
{
	t_square	*square;
	t_square	*best_square;
	int			x_obs;

	square = ft_init_square();
	best_square = NULL;
	while (square->ys < map->h - square->side + 1)
	{
		square->xs = 0;
		while (square->xs < map->w - square->side + 1 && square->ys < map->h - square->side + 1)
		{
			x_obs = ft_find_x_obs(square, map);
			if (x_obs == -1)
			{
				free(best_square);
				best_square = ft_copy_square(square);
				square->side += 1;
				continue ;
			}
			square->xs += 1;
		}
		square->ys += 1;
	}
	ft_print_filled_map(best_square, map);
}
