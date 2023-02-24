/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:53:51 by revieira          #+#    #+#             */
/*   Updated: 2023/02/22 17:02:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS
# define PUSH_SWAP_BONUS

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

int			matrix_is(char **matrix, int (*f)(char *));
long long 	ft_atoill(const char *str);
int			*normalize_numbers(int *int_array, int size);
int			*convert_to_int_array(char **char_array, int size);

int			check_args(int argc, char **argv);

t_stack		*new_node(int number, int index);
void		add_node_back(t_stack **head_stack, t_stack *new);
void		add_to_stack(t_stack **stack, int number, int index);
int			size_stack(t_stack **stack);
void		free_stack(t_stack **head_stack);

#endif
