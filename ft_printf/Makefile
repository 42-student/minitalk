# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smargine <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 21:49:01 by smargine          #+#    #+#              #
#    Updated: 2023/06/11 16:52:20 by smargine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_printf_lib.c

OBJ = $(SRC:%.c=%.o)

HEADER = ft_printf.h

AR = ar rcs

$(NAME): $(OBJ) $(HEADER)
							$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
				$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
