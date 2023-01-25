/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:47 by revieira          #+#    #+#             */
/*   Updated: 2023/01/25 17:50:11 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

//utils
int					*convert_to_int_array(char **char_array, int size);
int					matrix_is(char **matrix, int (*f)(char *));
long long			ft_atoif(const char *str);

//delet in utils
void				ft_print_stack(t_stack *stack);
void				test_stack(t_stack **s_a, t_stack **s_b);

//main
int					*check_and_convert(int argc, char **argv);
t_stack				**create_stack_a(int *int_array);

//check_args
int					repeated_number(char **argv);
int					check_order(int *int_array, int size);
int					*check_and_convert(int argc, char **argv);

//algorithm
void				three_numbers(t_stack **a);

//linked_stack
t_stack				*new_node(int data);
void				add_node_back(t_stack **head_stack, t_stack *new);
void				add_to_stack(t_stack **stack, int data);
void				free_stack(t_stack **head_stack);
int					size_stack(t_stack **stack);

//operations
int					swap_a(t_stack **head, int print);
int					swap_b(t_stack **head, int print);
void				swap_ab(t_stack **head_a, t_stack **head_b);
void				push_a(t_stack **head_a, t_stack **head_b);
void				push_b(t_stack **head_a, t_stack **head_b);
int					rotate_a(t_stack **head, int print);
int					rotate_b(t_stack **head, int print);
void				rotate_ab(t_stack **head_a, t_stack **head_b);
int					reverse_rotate_a(t_stack **head, int print);
int					reverse_rotate_b(t_stack **head, int print);
void				reverse_rotate_ab(t_stack **head_a, t_stack **head_b);

#endif
