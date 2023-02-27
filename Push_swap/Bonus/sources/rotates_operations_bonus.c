/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:59:38 by revieira          #+#    #+#             */
/*   Updated: 2023/02/27 14:45:52 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rotate_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (size_stack(stack) < 2)
		return (0);
	first = (*stack);
	last = (*stack);
	while (last->next)
		last = last->next;
	(*stack) = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

int	rotate_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (size_stack(stack) < 2)
		return (0);
	first = (*stack);
	last = (*stack);
	while (last->next)
		last = last->next;
	(*stack) = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

int	reverse_rotate_a(t_stack **stack)
{
	t_stack	*last;
	t_stack	*one_before_last;

	if (size_stack(stack) < 2)
		return (0);
	last = (*stack);
	one_before_last = NULL;
	while (last->next != NULL)
	{
		one_before_last = last;
		last = last->next;
	}
	one_before_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
	return (1);
}

int	reverse_rotate_b(t_stack **stack)
{
	t_stack	*last;
	t_stack	*one_before_last;

	if (size_stack(stack) < 2)
		return (0);
	last = (*stack);
	one_before_last = NULL;
	while (last->next != NULL)
	{
		one_before_last = last;
		last = last->next;
	}
	one_before_last->next = NULL;
	last->next = (*stack);
	(*stack) = last;
	return (1);
}
