/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:50 by revieira          #+#    #+#             */
/*   Updated: 2023/01/20 18:32:28 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("Node %d = [%d]\n", ++i, stack->data);
		stack = stack->next;
	}
	ft_printf("\n");
}

void	test_stack(t_stack **s_a, t_stack **s_b)
{
	ft_printf("Stack A:\n");
	ft_print_stack(*s_a);
	ft_printf("Stack B:\n");
	ft_print_stack(*s_b);
}

void	test_opers(t_stack *s_a, t_stack *s_b)
{
	push_b(&s_a, &s_b);
	push_b(&s_a, &s_b);
	push_b(&s_a, &s_b);
	rotate_a(&s_a, 1);
	rotate_b(&s_b, 1);
	reverse_rotate_a(&s_a, 1);
	reverse_rotate_b(&s_b, 1);
	swap_a(&s_a, 1);
	swap_b(&s_b, 1);
	swap_ab(&s_a, &s_b);
}

void	create_stacks(int *int_array)
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		i;

	s_a = NULL;
	s_b = NULL;
	i = -1;
	while (int_array[++i])
		add_to_stack(&s_a, int_array[i]);
	test_stack(&s_a, &s_b);
	ft_print_stack(s_a);
	ft_print_stack(s_b);
	free_stack(&s_a);
	free_stack(&s_b);
}

int	main(int argc, char **argv)
{
	int	*int_array;

	int_array = check_and_convert(argc, argv);
	if (!int_array)
		ft_exit_program("Error", 1);
	create_stacks(int_array);
	free(int_array);
	return (0);
}
