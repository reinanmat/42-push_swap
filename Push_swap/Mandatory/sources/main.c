/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:07:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 17:38:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	if (data->size <= 3)
		sort_three_numbers(&data->s_a);
	else if (data->size == 4)
		sort_four_numbers(&data->s_a, &data->s_b);
	else if (data->size == 5)
		sort_five_numbers(&data->s_a, &data->s_b);
	else
		sort_all(&data->s_a, &data->s_b);
}

void	init_data(t_data *data, int *int_array, int size)
{
	int	i;
	int	*norm_numbers;

	i = -1;
	data->size = size;
	data->s_a = NULL;
	data->s_b = NULL;
	norm_numbers = normalize_numbers(int_array, data->size);
	while (++i < data->size)
		add_to_stack(&data->s_a, int_array[i], norm_numbers[i]);
	set_pos(data->s_a);
	set_pos(data->s_b);
	free(int_array);
	free(norm_numbers);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*int_array;

	int_array = check_args(argc, argv);
	if (!int_array)
		ft_exit_program("Error", 1);
	init_data(&data, int_array, argc - 1);
	sort(&data);
	free_stack(&data.s_a);
	return (0);
}
