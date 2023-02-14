/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/14 13:03:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_algorithm(t_data *data)
{
	if (data->size <= 3)
		three_numbers(&data->a);
	if (data->size > 3)
		new_algorithm(data->a, data->b);
	/*else if (data->size == 4)
		four_numbers(&data->a, &data->b);
	else if (data->size == 5)
		five_numbers(&data->a, &data->b);*/
}

void	free_data(t_data *data)
{
	free(data->numbers);
	free(data->simpl_numbers);
	free_stack(&data->a);
}

void	init_data(int argc, char **argv, t_data *data)
{
	int	i;

	data->size = argc - 1;
	data->numbers = convert_to_int_array(++argv, data->size);
	data->simpl_numbers = normalize_numbers(data->numbers, data->size);
	data->b = NULL;
	i = -1;
	while (++i < data->size)
		add_to_stack(&data->a, data->numbers[i], data->simpl_numbers[i]);
}

int	main(int argc, char **argv)
{
	t_data data;

	if (!check_args(argc, argv))
		ft_exit_program("Error", 1);
	init_data(argc, argv, &data);
	choice_algorithm(&data);
	free_data(&data);
	return (0);
}
