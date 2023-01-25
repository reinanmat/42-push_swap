/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:50 by revieira          #+#    #+#             */
/*   Updated: 2023/01/25 17:51:47 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    choice_algorithm(t_stack **a, t_stack **b, int size)
{
    (*b) = NULL;
    if (size == 3)
        three_numbers(a);
}

void	create_stacks(int *int_array, int size)
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		i;

	s_a = NULL;
	s_b = NULL;
	i = -1;
	if (!check_order(int_array, size))
		return ;
	while (++i < size)
		add_to_stack(&s_a, int_array[i]);
    choice_algorithm(&s_a, &s_b, size);
	test_stack(&s_a, &s_b);
	free_stack(&s_a);
	//free_stack(&s_b);
}

int	main(int argc, char **argv)
{
	int	*int_array;

	int_array = check_and_convert(argc, argv);
	if (!int_array)
		ft_exit_program("Error", 1);
	create_stacks(int_array, argc - 1);
	free(int_array);
	return (0);
}
