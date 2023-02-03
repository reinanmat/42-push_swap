/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/03 18:50:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_algorithm(t_data *data)
{
	if (data->size <= 3)
		three_numbers(&data->a);
}

void	create_stacks(int *int_array, int size)
{
	t_data	data;
	int		i;

	data.a = NULL;
	data.b = NULL;
	data.size = size;
	if (!check_order(int_array, size))
		return ;
	i = -1;
	while (++i < size)
		add_to_stack(&data.a, int_array[i]);
	choice_algorithm(&data);
	test_stack(&data.a, &data.b);
	free_stack(&data.a);
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
