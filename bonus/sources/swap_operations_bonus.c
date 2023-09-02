/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:06:05 by revieira          #+#    #+#             */
/*   Updated: 2023/02/27 14:46:14 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_a(t_stack **stack)
{
	t_stack	*tmp;

	if (size_stack(stack) < 2)
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	return (1);
}

int	swap_b(t_stack **stack)
{
	t_stack	*tmp;

	if (size_stack(stack) < 2)
		return (0);
	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = (*stack);
	(*stack) = tmp;
	return (1);
}
