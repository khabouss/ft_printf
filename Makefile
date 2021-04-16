#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkhabous <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 21:35:15 by tkhabous          #+#    #+#              #
#    Updated: 2020/02/15 07:18:58 by tkhabous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_flagsreader.c ft_normkiller.c ft_printers.c ft_printf.c */*.c

TAG = *.o

all : $(NAME)

$(NAME):
	(cd libft && make)
	gcc -Wextra -Werror -Wall -c $(SRC)
	ar rsc $(NAME) $(TAG)

clean :
	@(cd libft && make clean)
	@rm -rf *.o */*.o

fclean : clean
	@(cd libft && make fclean)
	@rm -rf $(NAME)

re : fclean all
