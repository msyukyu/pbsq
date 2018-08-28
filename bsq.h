
#ifndef BSQ_H
# define BSQ_H
# define BUFFER_SIZE 4096
# define MAP_SIZE map->ye + 1
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_square
{
	int				xs;
	int				ys;
	int				xe;
	int				ye;
}
typedef struct		s_obs
{
	int				x;
	struct s_obs	*next;
}					t_obs;
typedef struct		s_map
{
	int				xs;
	int				ys;
	int				xe;
	int				ye;
	char			*map;
	t_obs			**obs;
}					t_map;
void				ft_putchar(char *str);
void				ft_putstr(char *str);
#endif
