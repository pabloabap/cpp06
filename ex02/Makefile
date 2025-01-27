# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabad-ap <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 10:24:21 by pabad-ap          #+#    #+#              #
#    Updated: 2025/01/24 18:51:29 by pabad-ap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= identifier 

CPP		= c++
CPP_FLAGS	= -Wall -Wextra -Werror -std=c++98 #-Wconversion

HEADERS		= Base.hpp
SRC		= main.cpp Base.cpp

OBJ		= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS) Makefile
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
