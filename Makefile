# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 19:21:50 by zminhas           #+#    #+#              #
#    Updated: 2021/10/22 18:51:30 by zminhas          ###   ########.fr        #
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
			srcs/push_swap/find_hold.c\
			srcs/push_swap/push.c\
			srcs/push_swap/read.c\
			srcs/push_swap/reverse_rotate.c\
			srcs/push_swap/rotate.c\
			srcs/push_swap/sort.c\
			srcs/push_swap/swap.c\
			srcs/push_swap/utils.c\
			srcs/push_swap/utils2.c\

SRCS_BONUS	=	srcs/checker/checker.c\
				srcs/checker/push.c\
				srcs/checker/read.c\
				srcs/checker/reverse_rotate.c\
				srcs/checker/rotate.c\
				srcs/checker/swap.c\
				srcs/checker/utils.c\
				srcs/checker/utils2.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}


NAME1	=	push_swap.a
NAME2	=	checker.a

EXEC1	=	push_swap
EXEC2	=	checker

LIB_PATH	=	./libft

.c.o:
		@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}

all:	${OBJS}
		@clear
		@make -C ${LIB_PATH}
		@mv ${LIB_PATH}/libft.a $(NAME1)
		@ar -rcs $(NAME1) ${OBJS}
		@gcc -Wall -Wextra -Werror $(NAME1) -o $(EXEC1)
		@echo "${GREEN}push_swap created !${RESET}"

bonus:	${OBJS_BONUS}
		@clear
		@make -C ${LIB_PATH}
		@mv ${LIB_PATH}/libft.a $(NAME2)
		@ar -rcs $(NAME2) ${OBJS_BONUS}
		@gcc -Wall -Wextra -Werror $(NAME2) -o $(EXEC2)
		@echo "${GREEN}checker created !${RESET}"
		

clean:
		@clear
		@rm -f ${OBJS}
		@rm -f ${OBJS_BONUS}
		@rm -f $(NAME1)
		@rm -f $(NAME2)
		@make clean -C ${LIB_PATH}
		@echo "${YELLOW}Objects cleaned !${RESET}"

fclean:
		@clear
		@rm -f ${OBJS}
		@rm -f ${OBJS_BONUS}
		@rm -f $(NAME1)
		@rm -f $(NAME2)
		@rm -f $(EXEC1)
		@rm -f $(EXEC2)
		@make fclean -C ${LIB_PATH}
		@echo "${RED}fclean done !${RESET}"

re:			fclean all

.PHONY:		all bonus clean fclean re