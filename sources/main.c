/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:50 by revieira          #+#    #+#             */
/*   Updated: 2023/01/19 19:11:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**create_stack_a(int *int_array)
{
	int		i;
	t_stack	**s_a;

	s_a = (t_stack **)ft_calloc(sizeof(t_stack), ft_intlen(int_array) + 1);
	i = -1;
	while (int_array[++i])
		add_to_stack(s_a, int_array[i]);
	return (s_a);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack)
	{
		ft_printf("%d = [%d]\n", ++i, stack->data);
		stack = stack->next;
	}
    ft_printf("\n");
}

void	create_stacks(int *int_array)
{
	t_stack	**s_a;
	t_stack	**s_b;
	int		size;

	size = ft_intlen(int_array);
	s_a = create_stack_a(int_array);
	s_b = (t_stack **)ft_calloc(sizeof(t_stack), size + 1);
    s_b = s_a;
	ft_print_stack(*s_a);
    ft_print_stack(*s_b);
    swap_a(s_a);
    swap_b(s_a);
    push_a(s_a, s_b);
	ft_print_stack(*s_a);
    ft_print_stack(*s_b);
	free(s_b);
	free_stack(s_a);
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
