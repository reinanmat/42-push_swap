/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:46:37 by revieira          #+#    #+#             */
/*   Updated: 2023/01/20 18:19:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*aux;

	if (size_stack(head_b) < 1)
		return ;
	aux = (*head_b)->next;
	(*head_b)->next = (*head_a);
	(*head_a) = (*head_b);
	(*head_b) = aux;
	ft_printf("pa\n");
}

void	push_b(t_stack **head_a, t_stack **head_b)
{
	t_stack	*aux;

	if (size_stack(head_a) < 1)
		return ;
	aux = (*head_a)->next;
	(*head_a)->next = (*head_b);
	(*head_b) = (*head_a);
	(*head_a) = aux;
	ft_printf("pb\n");
}
