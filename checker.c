#include "bsq.h"

t_map	*ft_add_obs(t_map *map, t_checkmap *checkmap)
{
	checkmap->current = malloc(sizeof(t_obs));
	checkmap->current->x = checkmap->w;
	checkmap->current->next = NULL;
	if (checkmap->previous == NULL)
		map->obs[checkmap->h] = checkmap->current;
	else
		checkmap->previous->next = checkmap->current;
	checkmap->previous = checkmap->current;
	return (map);
}

t_map	*ft_check_instructions(t_map *map, t_checkmap *checkmap)
{
	char	c;
	int		authorized;

	c = checkmap->segmap->seg[checkmap->i];
	authorized = ft_strlen_modif(map->segmap->seg);
	if (checkmap->i >= authorized - 3)
	{
		if (checkmap->n_char % 3 == 0)
			map->c_empty = c;
		else if (checkmap->n_char % 3 == 1)
			map->c_obs = c;
		else
			map->c_full = c;
		(checkmap->n_char)++;
		if (checkmap->n_char == 3 && (map->c_full == map->c_obs ||
					map->c_full == map->c_empty || map->c_obs == map->c_empty))
			return (NULL);
	}
	return (map);
}

int		ft_is_valid_char(t_map *map, t_checkmap *checkmap)
{
	char	c;

	c = checkmap->segmap->seg[checkmap->i];
	return (checkmap->h == -1 || c == '\n' || c == map->c_obs ||
			c == map->c_full || c == map->c_empty);
}

t_map	*ft_check_char(t_map *map, t_checkmap *checkmap)
{
	char	c;

	c = checkmap->segmap->seg[checkmap->i];
	if (ft_is_valid_char(map, checkmap) == 1)
	{
		if (c == '\n')
		{
			(checkmap->h)++;
			map->obs[checkmap->h] = NULL;
			checkmap->previous = NULL;
			if (checkmap->h == 1)
				map->w = checkmap->w;
			if (map->w == checkmap->w)
				checkmap->w = 0;
			else if (checkmap->h > 0)
				return (NULL);
			return (map);
		}
		if (checkmap->h > -1 && c == map->c_obs)
			map = ft_add_obs(map, checkmap);
		else if (checkmap->h == -1)
			map = ft_check_instructions(map, checkmap);
		checkmap->w = (checkmap->h > -1) ? checkmap->w + 1 : checkmap->w;
	}
	return ((ft_is_valid_char(map, checkmap)) ? map : NULL);
}

t_map	*ft_check_map(t_map *map)
{
	t_checkmap	*checkmap;

	checkmap = malloc(sizeof(t_checkmap));
	checkmap->w = 0;
	checkmap->h = -1;
	checkmap->i = -1;
	checkmap->n_char = 0;
	checkmap->segmap = map->segmap;
	map->h = ft_atoi(map->segmap->seg);
	map->w = 0;
	map->obs = malloc(sizeof(t_obs*) * map->h);
	while (map != NULL && checkmap->segmap != NULL)
	{
		while (map != NULL && checkmap->segmap->seg[++(checkmap->i)])
			map = ft_check_char(map, checkmap);
		checkmap->segmap = checkmap->segmap->next;
		checkmap->i = -1;
	}
	if (map != NULL && checkmap->h == map->h && checkmap->n_char == 3)
		return (map);
	else
		return (NULL);
}
