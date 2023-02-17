/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:47 by revieira          #+#    #+#             */
/*   Updated: 2023/02/17 16:06:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				number;
	int				idx;
	int				curr_pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				size;
	int				*numbers;
	int				*simpl_numbers;
	t_stack			*s_a;
	t_stack			*s_b;
}					t_data;

//utils
int					*convert_to_int_array(char **char_array, int size);
int					matrix_is(char **matrix, int (*f)(char *));
int					*normalize_numbers(int *int_array, int size);
long long			ft_atoif(const char *str);

//delet in utils
void				ft_print_stack(t_stack *stack);
void				test_stack(t_stack **s_a, t_stack **s_b);

//main
t_stack				**create_stack_a(int *int_array);

//check_args
int					duplicated_number(char **argv);
int					check_order(int *int_array, int size);
int					check_args(int argc, char **argv);

//algorithm
void				three_numbers(t_stack **stack);
void				four_numbers(t_stack **s_a, t_stack **s_b);
void				five_numbers(t_stack **s_a, t_stack **s_b);

void				new_algorithm(t_stack **s_a, t_stack **s_b);
int					middle_stack(t_stack **stack);
void				calculate_cost(t_stack **s_a, t_stack **s_b);

//linked_stack
t_stack				*new_node(int value, int index);
void				add_node_back(t_stack **head_stack, t_stack *new);
void				add_to_stack(t_stack **head_stack, int value, int index);
void				free_stack(t_stack **head_stack);
int					size_stack(t_stack **stack);

//pos
void				get_pos(t_stack	*stack);
int					middle_stack(t_stack **stack);

//new_algorith,
void				calculate_target_pos(t_stack **s_a, t_stack **s_b);

//calculate_cost
int					ft_abs(int num);
int					get_small_cust(t_stack	**s_b);
void				exec_small_cost(t_stack	**s_a, t_stack **s_b, int idx);

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
