/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BSQ.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 11:45:37 by rhunders          #+#    #+#             */
/*   Updated: 2018/08/28 12:06:22 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_obs
{
	int x;
	struct s_obs *next;
}				t_obs;
typedef struct	s_map
{
	int xs;
	int ys;
	int xe;
	int ye;
	char *map;
	t_obs **obs;
}				t_map;
#endif
