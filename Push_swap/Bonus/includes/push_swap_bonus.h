/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:47 by revieira          #+#    #+#             */
/*   Updated: 2023/02/27 18:46:48 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"
# include <stdlib.h>

# define VALIDATED_OPERS "pa\npb\nsa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\n\0"

typedef struct s_stack
{
	int				number;
	int				idx;
	struct s_stack	*next;
}					t_stack;

typedef struct s_opers
{
	char 			*operation;
	struct s_opers	*next;
}					t_opers;

typedef struct s_data
{
	t_stack			*s_a;
	t_stack			*s_b;
	t_opers			*operations;
	char			*valided_operations[12];
	int				size;
}					t_data;

//utils
int					ft_issort(t_stack **stack);
long long			ft_atoif(char *str);
int					*convert_to_int_array(char **matrix, int size);
int					*normalize_numbers(int *int_array, int size);

//stack_utils
t_stack				*new_node(int number);
void				add_node_back(t_stack **head_stack, t_stack *new);
void				add_to_stack(t_stack **head_stack, int number);
int					size_stack(t_stack **stack);
void				free_stack(t_stack **head_stack);

void				add_operation(t_opers **head_node, char *operation);
t_opers				*new_node_oper(char *operation);

//main
void				print_opers(t_opers **operations);
void				init_data(t_data *data, int *int_array, int size);
void				sort(t_data *data);

//check_args
int					*check_args(int argc, char **argv);

//read_input_bonus
int					read_operations(t_data *data);

//operations
void				exec_operation(char *oper, t_stack **s_a, t_stack **s_b);
int					push_a(t_stack **s_a, t_stack **s_b);
int					push_b(t_stack **s_a, t_stack **s_b);
int					swap_a(t_stack **stack);
int					swap_b(t_stack **stack);
int					swap_ab(t_stack **s_a, t_stack **s_b);
int					rotate_a(t_stack **stack);
int					rotate_b(t_stack **stack);
int					rotate_ab(t_stack **s_a, t_stack **s_b);
int					reverse_rotate_a(t_stack **stack);
int					reverse_rotate_b(t_stack **stack);
int					reverse_rotate_ab(t_stack **s_a, t_stack **s_b);

#endif
