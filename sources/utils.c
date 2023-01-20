/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:58:57 by revieira          #+#    #+#             */
/*   Updated: 2023/01/20 18:19:34 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_int_array(char **char_array)
{
	int	i;
	int	*int_array;

	i = -1;
	int_array = (int *)ft_calloc(sizeof(int), ft_matrixlen(char_array) + 1);
	while (char_array[++i])
		int_array[i] = ft_atoi(char_array[i]);
	return (int_array);
}

int	ft_intlen(int *int_array)
{
	int	size;

	size = 0;
	while (int_array && int_array[size])
		size++;
	return (size);
}

int	ft_matrixlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
		i++;
	return (i);
}
