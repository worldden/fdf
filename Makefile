#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/02 12:43:43 by ddehtyar          #+#    #+#              #
#    Updated: 2018/06/02 13:41:55 by ddehtyar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

FL	=  -Wall -Werror -Wextra

SRC = main.c read.c drop.c help.c hook_info.c help_sec.c

LIB     =./libft/libft.a

FLGMLX     = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	cc $(FL) -o $(NAME) $(SRC) $(LIB) $(FLGMLX)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re