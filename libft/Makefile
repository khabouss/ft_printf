# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 19:42:44 by tkhabous          #+#    #+#              #
#    Updated: 2019/12/14 15:16:58 by tkhabous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
AR = ar
NAME = libft.a
flags = -Wall -Wextra -Werror
SRCS = *.c

all : $(NAME)

$(NAME):
	@$(CC) $(flags) -c $(SRCS)
	@$(AR) rsc $(NAME) *.o

bonus:
	echo "Taha Khabouss"

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf *.a

re: fclean all
