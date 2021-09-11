# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 19:21:50 by zminhas           #+#    #+#              #
#    Updated: 2021/09/11 15:06:21 by zminhas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	main.c\
			srcs/init.c\
			srcs/read.c\

OBJS	=	${SRCS:.c=.o}

EXEC	=	push_swap

LIB_PATH	=	./libft

.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all:	${OBJS}
		@make -C ${LIB_PATH}
		@gcc -Wall -Wextra -Werror main.c $(LIB_PATH)/libft.a -o $(EXEC)
		@echo "${GREEN}push_swap created !${RESET}"

clean:
		@rm -f ${OBJS}
		@make clean -C ${LIB_PATH}
		@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
		@rm -f ${OBJS}
		@rm -f $(EXEC)
		@make fclean -C ${LIB_PATH}
		@echo "${RED}fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re