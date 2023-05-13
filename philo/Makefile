# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpelaez- <jpelaez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 17:22:57 by jpelaez-          #+#    #+#              #
#    Updated: 2023/05/13 16:50:15 by jpelaez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = main.c init.c utils.c\

OBJECT = $(SRC:.c=.o)

HEADER = philo.h

FLAGS = -Wall -Wextra -Werror 
IFLAGS = -I $(HEADER) 

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