/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/06 19:07:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isSort(t_stack **stack)
{
	t_stack	*aux;
	int		save_num;

	aux = (*stack);
	save_num = aux->data;
	while (aux->next)
	{
		aux = aux->next;
		if (save_num > aux->data)
			return (0);
		save_num = aux->data;
	}
	return (1);
}

void	three_numbers(t_stack **stack)
{
	while (!ft_isSort(stack))
	{
		if ((*stack)->data > (*stack)->next->data)
			exec_operation("sa", stack, NULL);
		else
			exec_operation("rra", stack, NULL);
	}
}
