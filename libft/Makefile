# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 18:35:49 by zminhas           #+#    #+#              #
#    Updated: 2020/12/28 18:12:53 by zminhas          ###   ########.fr        #
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

SRCS	=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c

SRCS_BONUS	=	ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstclear.c\
				ft_lstdelone.c\
				ft_lstiter.c\
				ft_lstlast.c\
				ft_lstmap.c\
				ft_lstnew.c\
				ft_lstsize.c

OBJS	=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME	=	libft.a

.c.o:
			@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}
			@echo "${LIGHTPURPLE}Compilation of :$<${RESET}"

$(NAME):	${OBJS}
			@ar -rcs ${NAME} ${OBJS}
			@ranlib ${NAME}
			@echo "${GREEN}Library created !${RESET}"

all:		${NAME}

clean:
			@rm -f ${OBJS}
			@rm -f ${OBJS_BONUS}
			@echo "${RED}Objects cleaned !${RESET}"

fclean:
			@rm -f ${OBJS}
			@rm -f ${NAME}
			@rm -f ${OBJS_BONUS}
			@echo "${RED}fclean done !${RESET}"

bonus:		${OBJS_BONUS}
			@ar -rcs ${NAME} ${OBJS_BONUS}
			@ranlib ${NAME}
			@echo "${PURPLE}Bonus !${RESET}"

full:		${OBJS} ${OBJS_BONUS}
			@ar -rcs ${NAME} ${OBJS} ${OBJS_BONUS}
			@ranlib ${NAME}
			@echo "${PURPLE}JeeJ fuller !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re bonus full