/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:06:05 by revieira          #+#    #+#             */
/*   Updated: 2023/02/03 19:00:17 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack **head)
{
	t_stack	*aux;

	if (size_stack(head) < 2)
		return (0);
	aux = (*head)->next;
	(*head)->next = (*head)->next->next;
	aux->next = (*head);
	(*head) = aux;
	return (1);
}

int	swap_b(t_stack **head)
{
	t_stack	*aux;

	if (size_stack(head) < 2)
		return (0);
	aux = (*head)->next;
	(*head)->next = (*head)->next->next;
	aux->next = (*head);
	(*head) = aux;
	return (1);
}
