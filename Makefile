# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/29 17:58:40 by dabeloos          #+#    #+#              #
#    Updated: 2018/08/29 17:58:42 by dabeloos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsq

C_FILES		= main.c solver.c string_utils.c checker.c

FLAGS		= -Wall -Wextra -Werror

$(NAME):
		gcc -o $(NAME) $(FLAGS) $(C_FILES)

all:		$(NAME)

clean:
		rm -f $(NAME)

fclean:		clean

re:		fclean all
