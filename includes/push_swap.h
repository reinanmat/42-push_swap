/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:14:47 by revieira          #+#    #+#             */
/*   Updated: 2023/01/19 19:09:59 by revieira         ###   ########.fr       */
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

int					*convert_to_int_array(char **char_array);

//main
int					*check_and_convert(int argc, char **argv);
t_stack				**create_stack_a(int *int_array);

//utils
int					ft_matrixlen(char **matrix);
int					ft_intlen(int *int_array);
void				ft_print_stack(t_stack *stack);

//linked_stack
t_stack				*new_node(int data);
void				add_node_back(t_stack **head_stack, t_stack *new);
void				add_to_stack(t_stack **stack, int data);
void				free_stack(t_stack **head_stack);
int					size_stack(t_stack **stack);

void				swap_a(t_stack **head);
void				swap_b(t_stack **head);
void				push_a(t_stack **stack_a, t_stack **stack_b);

#endif
