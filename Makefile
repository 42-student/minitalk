# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smargine <smargine@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/03 03:31:48 by smargine          #+#    #+#              #
#    Updated: 2023/08/04 07:55:25 by smargine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mintlk

FTPRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a

CCFLAGS = cc -Wall -Werror -Wextra
RM = rm -rf

SERVER = server
CLIENT = client

SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c
SRCS_SERVER_BONUS = src/server_bonus.c
SRCS_CLIENT_BONUS = src/client_bonus.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

all: $(SERVER) $(CLIENT)

$(NAME): all

$(FTPRINTF):
				$(MAKE) -C ./ft_printf

$(LIBFT):
				$(MAKE) -C ./libft

$(SERVER): $(OBJS_SERVER) $(FTPRINTF) $(LIBFT)
						$(CCFLAGS) $(OBJS_SERVER) $(FTPRINTF) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT) $(FTPRINTF) $(LIBFT)
						$(CCFLAGS) $(OBJS_CLIENT) $(FTPRINTF) $(LIBFT) -o $(CLIENT)

bonus: $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(FTPRINTF) $(LIBFT)
		$(CCFLAGS) $(OBJS_SERVER_BONUS) $(FTPRINTF) $(LIBFT) -o $(SERVER)
		$(CCFLAGS) $(OBJS_CLIENT_BONUS) $(FTPRINTF) $(LIBFT) -o $(CLIENT)

clean:
		$(MAKE) clean -C ./ft_printf
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)

fclean: clean
		$(MAKE) fclean -C ./ft_printf
		$(MAKE) fclean -C ./libft
		$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re
