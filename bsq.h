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
typedef struct		s_map
{
	int				xs;
	int				ys;
	int				w;
	int				h;
	char			c_full;
	char			c_empty;
	char			c_obs;
	char			*map;
	t_obs			**obs;
}					t_map;
int					ft_atoi(char *str);
char				*ft_strcat(char *dest, char *src);
void				ft_strcpy(char *dest, char *src);
int					ft_find_x_obs(t_square *square, t_map *map);
t_square			*ft_init_square(void);
t_square			*ft_copy_square(t_square *square);
void				ft_print_filled_map(t_square *best_square, t_map *map);
void				ft_solve_map(t_map *map);
t_map				*ft_read_map(int fd);
int					ft_check_map(t_map *map);
char				*ft_malloc(char *str, int n_read, int n_buff, char *buff);
//supprimer
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int i);
#endif
