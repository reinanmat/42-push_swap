/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:58:57 by revieira          #+#    #+#             */
/*   Updated: 2023/02/14 16:57:16 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	matrix_is(char **matrix, int (*f)(char *))
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (!f(matrix[i]))
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atoill(const char *str)
{
	int			sign;
	long long	result;
	int			i;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	if (!(ft_isdigit(str[i])))
		return (0);
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

int	*convert_to_int_array(char **char_array, int size)
{
	int			i;
	int			*int_array;
	long long	number;

	int_array = (int *)ft_calloc(sizeof(int), size + 1);
	i = -1;
	while (char_array[++i])
	{
		if (ft_strlen(char_array[i]) > 11)
		{
			free(int_array);
			return (NULL);
		}
		number = ft_atoill(char_array[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			free(int_array);
			return (NULL);
		}
		int_array[i] = (int)number;
	}
	return (int_array);
} 

int	*normalize_numbers(int *int_array, int size)
{
	int	*indexs;
	int	i;
	int	j;

	i = 0;
	indexs = (int *)ft_calloc(sizeof(int), size + 1);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (int_array[i] > int_array[j])
				indexs[i]++;
			j++;
		}
		indexs[i]++;
		i++;
	}
	return (indexs);
}

void	test_stack(t_stack **s_a, t_stack **s_b)
{
	ft_printf("\nStack A:\n");
	ft_print_stack(*s_a);
	ft_printf("Stack B:\n");
	ft_print_stack(*s_b);
}

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		ft_printf("Node %d = [%d]	idx is %d, pos is %d and tag_pos is %d\n", ++i, stack->number, stack->idx, stack->pos, stack->tag_pos);
		stack = stack->next;
	}
	ft_printf("\n");
}
