/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:46:37 by revieira          #+#    #+#             */
/*   Updated: 2023/02/02 19:50:54 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*aux;

	if (size_stack(head_b) < 1)
		return (0);
	aux = (*head_b)->next;
	(*head_b)->next = (*head_a);
	(*head_a) = (*head_b);
	(*head_b) = aux;
	return (1);
}

int	push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*aux;

	if (size_stack(head_a) < 1)
		return (0);
	aux = (*head_a)->next;
	(*head_a)->next = (*head_b);
	(*head_b) = (*head_a);
	(*head_a) = aux;
	return (1);
}
