/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:45:46 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/28 12:41:49 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_map	ft_read_map(int	fd)
{

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
