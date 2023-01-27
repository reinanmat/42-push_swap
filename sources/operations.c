/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:38 by revieira          #+#    #+#             */
/*   Updated: 2023/01/27 16:03:44 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_operations(char *oper, t_data *data)
{
	int ret;

	ret = 0;
	if (ft_strcmp(oper, "sa")
		ret = swap_a(data.stack_a);
	else if (ft_strcmp(oper. "sb")
		ret = swap_b(data.stack_b);
	return (ret);
}

int	push_operations(char *oper, t_data *data)
{
	int	ret;

	ret = 0;
	if (ft_strcmp(oper, "pa")
		ret = push_a(data.stack_a, data.stack_b);
	else if (ft_strcmp(oper, "pb");
		ret = push_b(data.stack_a, data.stack_b);
	
}

void	exec_oper(char *oper, t_data *data)
{
	int	ret;

	ret = 0;
	if (*oper == 's')
		ret = swap_operations(oper, data);
	else if (*oper == 'p')
		ret = push_operations(oper, data);
	else if (*oper == 'r')
		ret = rotate_operations(oper, data);
	if (ret)
		ft_printf("%s/n", oper);
}

