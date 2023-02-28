# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 11:35:54 by revieira          #+#    #+#              #
#    Updated: 2023/02/28 15:09:05 by revieira         ###   ########.fr        #
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

FILES = calculate_cost check_args exec_operation exec_small_cost get_positions \
		main push_operations rotates_operations swap_operations sort sort_big  \
		stack_utils utils

BONUS_FILES = main_bonus check_args_bonus utils_bonus exec_operation_bonus \
			  push_operations_bonus rotates_operations_bonus swap_operations_bonus \
			  stack_utils_bonus read_input_bonus nodes_opers

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

re_bonus: fclean bonus

.PHONY: all clean fclean re

