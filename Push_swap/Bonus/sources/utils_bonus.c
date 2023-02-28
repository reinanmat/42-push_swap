/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:58:57 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 15:45:28 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_issort(t_stack **stack)
{
	t_stack	*tmp;
	int		save_num;

	tmp = (*stack);
	save_num = tmp->number;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (save_num > tmp->number)
			return (0);
		save_num = tmp->number;
	}
	return (1);
}

long long	ft_atoill(char *str)
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

int	*convert_to_int_array(char **matrix, int size)
{
	int			i;
	int			*int_array;
	long long	number;

	int_array = (int *)ft_calloc(sizeof(int), size + 1);
	i = -1;
	while (matrix[++i])
	{
		number = ft_atoill(matrix[i]);
		if (number > 2147483647 || number < -2147483648)
		{
			free(int_array);
			return (NULL);
		}
		int_array[i] = (int)number;
	}
	return (int_array);
}
