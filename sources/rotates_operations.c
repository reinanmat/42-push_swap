/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:59:38 by revieira          #+#    #+#             */
/*   Updated: 2023/02/13 19:22:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (size_stack(head) < 2)
		return (0);
	first = (*head);
	last = (*head);
	while (last->next)
		last = last->next;
	(*head) = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

int	rotate_b(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (size_stack(head) < 2)
		return (0);
	first = (*head);
	last = (*head);
	while (last->next)
		last = last->next;
	(*head) = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

int	reverse_rotate_a(t_stack **head)
{
	t_stack	*last;
	t_stack	*one_before_last;

	if (size_stack(head) < 2)
		return (0);
	last = (*head);
	one_before_last = NULL;
	while (last->next != NULL)
	{
		one_before_last = last;
		last = last->next;
	}
	one_before_last->next = NULL;
	last->next = (*head);
	(*head) = last;
	return (1);
}

int	reverse_rotate_b(t_stack **head)
{
	t_stack	*last;
	t_stack	*one_before_last;

	if (size_stack(head) < 2)
		return (0);
	last = (*head);
	one_before_last = NULL;
	while (last->next != NULL)
	{
		one_before_last = last;
		last = last->next;
	}
	one_before_last->next = NULL;
	last->next = (*head);
	(*head) = last;
	return (1);
}
