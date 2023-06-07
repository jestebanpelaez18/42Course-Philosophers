# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 17:22:57 by jpelaez-          #+#    #+#              #
#    Updated: 2023/06/07 11:00:11 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c init.c utils.c\
actions.c start_routine.c utils_2.c\

OBJECT = $(SRC:.c=.o)

HEADER = philo.h

FLAGS = -Wall -Wextra -Werror 
IFLAGS = -I $(HEADER) 
SANITIZE = -fsanitize=thread -g -O1
CC = CC 

all: $(NAME) 

$(NAME):  $(OBJECT) 
		$(CC) $(FLAGS) $(IFLAGS) $(OBJECT) -o $(NAME) 

	
clean:
	rm -f $(OBJECT) 

fclean: clean
	   rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean