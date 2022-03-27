# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 16:54:54 by tsuetsug          #+#    #+#              #
#    Updated: 2022/03/27 10:41:15 by tsuetsug         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OFF		= \033[0m

NAME	= philo

SRCS	= srcs/error.c srcs/ft_atoi.c srcs/philo_act.c srcs/philosophers.c \
			srcs/data_init.c

OBJ		= *.o

HEADERS	= includes/philosophers.c

CC		= cc
CC_FLAGS= -Wall -Wextra -Werror
RM		= rm -f

all:	$(NAME)

$(NAME): $(SRCS) $(0BJ)
	@echo "$(BWHITE)Compiling philo...$(OFF)"
	$(CC) $(CC_FLAGS) -I $(HEADERS) -c $(SRCS)
	$(CC) -o $(NAME) $(OBJ) $(CC_FLAGS)
	@echo "$(BGREEN)philo build completed.$(OFF)"

clean:
	@echo "$(BWHITE)Removing object-files...$(OFF)"
	$(RM) $(OBJ)
	@echo "$(BGREEN)Clean done.$(OFF)"

fclean:	clean
	@echo "$(BWHITE)Removing object-files and binary-files...$(OFF)"
	$(RM) $(NAME)
	@echo "$(BGREEN)Fclean done.$(OFF)"

re:		fclean all

debug:
	$(CC) -g $(CC_FLAGS) -I$(HEADERS) $(SRCS) -o $(NAME)

.PHONY:		all clean fclean re debug