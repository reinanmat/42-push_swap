/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:47 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 16:14:07 by revieira         ###   ########.fr       */
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
	t_stack			*s_a;
	t_stack			*s_b;
}					t_data;

//utils
int					ft_abs(int num);
int					matrix_is(char **matrix, int (*f)(char *));
long long			ft_atoif(char *str);
int					*convert_to_int_array(char **matrix, int size);
int					*normalize_numbers(int *int_array, int size);

//stack_utils
t_stack				*new_node(int number, int idx);
void				add_node_back(t_stack **head_stack, t_stack *new);
void				add_to_stack(t_stack **head_stack, int number, int idx);
int					size_stack(t_stack **stack);
void				free_stack(t_stack **head_stack);

//delet in utils
void				ft_print_stack(t_stack *stack);
void				test_stack(t_stack **s_a, t_stack **s_b);

//main
void				init_data(t_data *data, int *int_array, int size);
void				sort(t_data *data);

//check_args
int					duplicated_number(char **argv);
int					check_order(int *int_array, int size);
int					*check_args(int argc, char **argv);

//sort
void				sort_three_numbers(t_stack **s_a);
void				sort_four_numbers(t_stack **s_a, t_stack **s_b);
void				sort_five_numbers(t_stack **s_a, t_stack **s_b);
void				put_value_in_top(t_stack **s_a, int index, int pos);
int					find_index(t_stack **stack, int wanted);
int					ft_issort(t_stack **stack);

//sort_big
int					find_stack(t_stack **stack, int idx);
void				send_to_stack_b(t_stack **s_a, t_stack **s_b);
void				exec_rotate_or_reverse_rotate(t_stack **s_a);
void				sort_all(t_stack **s_a, t_stack **s_b);

//get_positions
int					middle_stack(t_stack **stack);
void				set_pos(t_stack *stack);
int					find_high_idx(t_stack **stack);
int					get_approximate_highest_idx(t_stack **stack, int idx);
void				calculate_target_pos(t_stack **s_a, t_stack **s_b);

//exec_small_cost
void				exec_small_cost(t_stack **s_a, t_stack **s_b, int idx);

//calculate_cost
int					ft_abs(int num);
void				calculate_cost(t_stack **s_a, t_stack **s_b);
int					get_small_cost(t_stack	**s_b);

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
