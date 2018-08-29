NAME		= bsq

C_FILES		= main.c solver.c string_utils.c

FLAGS		= -Wall -Wextra -Werror

$(NAME)
		gcc -o $(NAME) $(FLAGS) $(C_FILES)

all:		$(NAME)

clean:
		rm -f $(NAME)

fclean:		clean

re:		fclean all
