# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/05 12:42:42 by kyuki             #+#    #+#              #
#    Updated: 2021/07/05 12:42:43 by kyuki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	server
NAME1	=	client

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

LFPATH	=	./libft

SRCDIR  = ./srcs/

SRCNAME_SERVER	=	server
SRCNAME_CLIENT	=	client

SRCS_SERVER	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME_SERVER)))
SRCS_CLIENT	=	$(addsuffix .c, $(addprefix srcs/, $(SRCNAME_CLIENT)))

OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

.PHONY: all
all	:	$(NAME) $(NAME1) ## Run compile

$(NAME)	:	${OBJS_SERVER}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C libft/.
			$(CC) -g ${OBJS_SERVER} ${LFPATH}/libft.a $(CFLAGS) -o ${NAME}
			@echo "Complete\033[0m"

$(NAME1)	:	${OBJS_CLIENT}
			@echo "\n\033[0;32mCompiling..."
			$(MAKE) -C libft/.
			$(CC) -g ${OBJS_CLIENT} ${LFPATH}/libft.a $(CFLAGS) -o ${NAME1}
			@echo "Complete\033[0m"

.PHONY: clean
clean	:	## Remove object
			@echo "\033[0;33mCleaning..."
			$(MAKE) clean -C libft/.
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)
			@echo "\033[0m"

.PHONY: fclean
fclean	:	clean ## Remove object and static
			@echo "\033[0;33mRemoving executable..."
			$(MAKE) fclean -C libft/.
			$(RM) $(NAME)
			$(RM) $(NAME1)
			@echo "\033[0m"

.PHONY: re
re	:	fclean all ## Retry cmpiles

.PHONY: bonus
bonus: $(NAME) $(NAME1) ## Run bonus

.PHONY: test1
test_script	: ## ./client server_PID `python -c "print('string' * (int)itr_num)"`

.PHONY: help
help	: ## Display this help
	@grep -E '^[a-zA-Z1-9_-]+	:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
