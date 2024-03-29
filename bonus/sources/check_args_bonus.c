/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:05:32 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 19:47:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	has_duplicated_number(char **argv)
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

static int	check_all(char *curr_arg)
{
	int	i;

	i = 0;
	while (curr_arg[i] == ' ')
		i++;
	if (curr_arg[i] == '\0')
		return (0);
	if (curr_arg[i] == '-' || curr_arg[i] == '+')
		i++;
	if (!ft_isdigit(curr_arg[i]) || curr_arg[i] == '\0')
		return (0);
	while (ft_isdigit(curr_arg[i]))
		i++;
	while (curr_arg[i] == ' ')
		i++;
	if (curr_arg[i] != '\0')
		return (0);
	return (1);
}

static int	check_argument(char **argv, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!argv[i] || !check_all(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	*check_args(int argc, char **argv)
{
	int	*int_array;

	++argv;
	if (argc == 1)
		exit(0);
	if (!check_argument(argv, argc - 1))
		return (0);
	if (!has_duplicated_number(argv))
		return (0);
	int_array = convert_to_int_array(argv, argc - 1);
	if (!int_array)
		return (0);
	return (int_array);
}
