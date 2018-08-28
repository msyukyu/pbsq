
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
void				ft_putchar(char *str);
void				ft_putstr(char *str);
char				*ft_strcat(char *dest, char *src);
void				ft_strcpy(char *dest, char *src);
#endif
