# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:35:54 by revieira          #+#    #+#              #
#    Updated: 2023/02/24 12:46:16 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

PATH_INCS  = ./Push_swap/Mandatory/includes/
PATH_SRCS  = ./Push_swap/Mandatory/sources/
PATH_OBJS  = ./Push_swap/Mandatory/objects/

PATH_BONUS_INCS  = ./Push_swap/Bonus/includes/
PATH_BONUS_SRCS  = ./Push_swap/Bonus/sources/
PATH_BONUS_OBJS  = ./Push_swap/Bonus/objects/

PATH_LIBFT = ./Libft/

FILES = main check_args linked_stack utils \
		push_operations swap_operations rotates_operations \
		exec_operation algorithm new_algorithm calculate_cost \
		position cost

BONUS_FILES = main_bonus check_args_bonus utils_bonus

SRCS = $(addprefix $(PATH_SRCS), $(addsuffix .c, $(FILES) ) )
OBJS = $(addprefix $(PATH_OBJS), $(addsuffix .o, $(FILES) ) )
BONUS_SRCS = $(addprefix $(PATH_BONUS_SRCS), $(addsuffix .c, $(BONUS_FILES) ) )
BONUS_OBJS = $(addprefix $(PATH_BONUS_OBJS), $(addsuffix .o, $(BONUS_FILES) ) )

LIBFT		= -L $(PATH_LIBFT) -lft
INCLUDES 	= -I $(PATH_INCS) -I $(PATH_LIBFT)includes
BONUS_INCLUDES = -I $(PATH_BONUS_INCS) -I $(PATH_LIBFT)includes
CFLAGS 		= -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(PATH_OBJS) $(OBJS)
	make -C $(PATH_LIBFT) --no-print-directory
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(PATH_OBJS):
	mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(PATH_BONUS_OBJS) $(BONUS_OBJS)
	make -C $(PATH_LIBFT) --no-print-directory
	cc $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) $(LIBFT)

$(PATH_BONUS_OBJS):
	mkdir -p $(PATH_BONUS_OBJS)

$(PATH_BONUS_OBJS)%.o: $(PATH_BONUS_SRCS)%.c
	cc $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	rm -rf $(PATH_OBJS)
	rm -rf $(PATH_BONUS_OBJS)
	make clean -C $(PATH_LIBFT) --no-print-directory

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
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

