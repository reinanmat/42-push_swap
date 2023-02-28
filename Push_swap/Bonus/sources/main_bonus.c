/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:48:26 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 19:48:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_data(t_data *data, int *int_array, int size)
{
	int	i;

	i = -1;
	data->size = size;
	data->s_a = NULL;
	data->s_b = NULL;
	data->operations = NULL;
	init_operations(data->valided_operations);
	while (++i < data->size)
		add_to_stack(&data->s_a, int_array[i]);
	free(int_array);
}

void	free_data(t_data *data)
{
	int	i;

	i = -1;
	while (data->valided_operations[++i])
		free(data->valided_operations[i]);
	if (size_stack(&data->s_a))
		free_stack(&data->s_a);
	if (size_stack(&data->s_b))
		free_stack(&data->s_b);
	if (size_opers(&data->operations))
		free_operation(&data->operations);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		*int_array;

	int_array = check_args(argc, argv);
	if (!int_array)
		ft_exit_program("Error", 1);
	init_data(&data, int_array, argc - 1);
	if (!read_operations(&data))
	{
		free_data(&data);
		ft_exit_program("Error", 1);
	}
	exec_opers(&data.operations, &data.s_a, &data.s_b);
	if (ft_issort(&data.s_a) && size_stack(&data.s_b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&data);
	return (0);
}
