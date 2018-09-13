# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrepak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 12:26:27 by nrepak            #+#    #+#              #
#    Updated: 2018/02/13 12:26:31 by nrepak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
LIB = libft.a
SRC = lemin.c ants.c comments.c create_room.c create_room2.c create_room3.c display.c errors.c find_path.c \
		link_levels.c make_free.c make_free2.c make_level.c make_link.c rescue_ants.c show_way.c startend.c \
		take_room.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ cd ./libft && make && mv $(LIB) ..
	@ gcc $(OBJ) $(LIB) -Wall -Wextra -Werror -o $(NAME)

%.o: %.c
	@ gcc -Wall -Wextra -Werror -c $<

clean:
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ cd ./libft && make fclean
	
re: fclean all
