# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yserkez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/13 14:47:18 by yserkez           #+#    #+#              #
#    Updated: 2018/12/24 12:28:00 by yserkez          ###   ########.fr        #
#    Updated: 2018/10/22 12:49:58 by yserkez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

all: $(NAME) clean

$(NAME):
	gcc -Wall -Werror -Wextra -c ./*.c;
	ar rc $(NAME) *.o;
	ranlib $(NAME);

clean:
	@rm -f *o;

fclean: clean
	@rm -f $(NAME);

re: fclean all

.PHONY : all, re, clean, fclean
