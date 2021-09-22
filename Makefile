# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 19:21:50 by zminhas           #+#    #+#              #
#    Updated: 2021/09/22 18:00:06 by zminhas          ###   ########.fr        #
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

SRCS	=	srcs/push_swap/push_swap.c\
			srcs/push_swap/chunk.c\
			srcs/push_swap/chunk2.c\
			srcs/push_swap/push.c\
			srcs/push_swap/read.c\
			srcs/push_swap/reverse_rotate.c\
			srcs/push_swap/rotate.c\
			srcs/push_swap/sort.c\
			srcs/push_swap/swap.c\
			srcs/push_swap/utils.c\
			srcs/push_swap/utils2.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\

OBJS	=	${SRCS:.c=.o}

NAME	=	push_swap.a

EXEC	=	push_swap

LIB_PATH	=	./libft

.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all:	${OBJS}
		@clear
		@make full -C ${LIB_PATH}
		@mv ${LIB_PATH}/libft.a $(NAME)
		@ar -rcs $(NAME) ${OBJS}
		@gcc -Wall -Wextra -Werror $(NAME) -o $(EXEC)
		@echo "${GREEN}push_swap created !${RESET}"

clean:
		@clear
		@rm -f ${OBJS}
		@rm -f $(NAME)
		@make clean -C ${LIB_PATH}
		@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
		@clear
		@rm -f ${OBJS}
		@rm -f $(NAME)
		@rm -f $(EXEC)
		@make fclean -C ${LIB_PATH}
		@echo "${RED}fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re