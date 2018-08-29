/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:02:58 by dabeloos          #+#    #+#             */
/*   Updated: 2018/08/29 18:02:59 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUFF_SIZE 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_square
{
	int				xs;
	int				ys;
	int				side;
}					t_square;
typedef struct		s_obs
{
	int				x;
	struct s_obs	*next;
}					t_obs;
typedef struct		s_segmap
{
	char			*seg;
	struct s_segmap	*next;
}					t_segmap;
typedef struct		s_map
{
	int				xs;
	int				ys;
	int				w;
	int				h;
	char			c_full;
	char			c_empty;
	char			c_obs;
	t_segmap		*segmap;
	t_obs			**obs;
	int				n_buff;
}					t_map;
typedef struct		s_checkmap
{
	int				w;
	int				h;
	int				i;
	int				n_char;
	t_segmap		*segmap;
	t_obs			*previous;
	t_obs			*current;
}					t_checkmap;
int					ft_atoi(char *str);
char				*ft_strcat(char *dest, char *src);
void				ft_strcpy(char *dest, char *src);
int					ft_strlen_modif(char *str);
int					ft_find_x_obs(t_square *square, t_map *map);
t_square			*ft_init_square(void);
t_square			*ft_copy_square(t_square *square);
void				ft_fill_map(t_square *best_square, t_map *map,
						char *final_map);
void				ft_print_filled_map(t_square *best_square, t_map *map);
void				ft_solve_map(t_map *map);
t_map				*ft_read_map(int fd);
int					ft_is_valid_char(t_map *map, t_checkmap *checkmap);
t_map				*ft_check_char(t_map *map, t_checkmap *checkmap);
t_map				*ft_check_instructions(t_map *map, t_checkmap *checkmap);
t_map				*ft_add_obs(t_map *map, t_checkmap *checkmap);
t_map				*ft_check_map(t_map *map);
char				*ft_malloc(char *str, int n_read, int n_buff, char *buff);
#endif
