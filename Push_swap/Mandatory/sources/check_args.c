/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:32 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 18:33:38 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicated_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_order(int *int_array, int size)
{
	int	save_num;
	int	i;

	if (size == 1)
		return (0);
	i = 0;
	save_num = int_array[i];
	while (++i < size)
	{
		if (save_num > int_array[i])
			return (1);
		save_num = int_array[i];
	}
	return (0);
}

int	*check_args(int argc, char **argv)
{
	int	*int_array;

	++argv;
	if (!matrix_is(argv, &ft_isnum))
		return (0);
	if (!has_duplicated_number(argv))
		return (0);
	int_array = convert_to_int_array(argv, argc - 1);
	if (!int_array)
		return (0);
	if (!check_order(int_array, argc - 1))
	{
		free(int_array);
		exit(0);
	}
	return (int_array);
}
