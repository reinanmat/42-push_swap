# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:35:54 by revieira          #+#    #+#              #
#    Updated: 2023/02/16 17:21:59 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

PATH_LIBFT = ./Libft/
PATH_INCS  = ./includes/
PATH_SRCS  = ./sources/
PATH_OBJS  = ./objects/

FILES = main check_args linked_stack utils \
		push_operations swap_operations rotates_operations \
		exec_operation algorithm new_algorithm calculate_cost \
		pos target_pos

SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES) ) )
OBJS = $(addprefix $(PATH_OBJS), $(addsuffix .o, $(FILES) ) )

LIBFT		= -L $(PATH_LIBFT) -lft
INCLUDES 	= -I $(PATH_INCS) -I $(PATH_LIBFT)includes
CFLAGS 		= -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS)
	make -C $(PATH_LIBFT) --no-print-directory
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
		cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT) --no-print-directory

fclean: clean
	rm -f $(NAME)
	make fclean -C $(PATH_LIBFT) --no-print-directory

re: fclean all

test3:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-50 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test5:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-50 -n 5))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l


test100:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-1000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500:	$(NAME)	
	$(eval ARG = $(shell shuf -i 0-2000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re

