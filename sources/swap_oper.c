/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:06:05 by revieira          #+#    #+#             */
/*   Updated: 2023/01/20 18:30:11 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack **head, int print)
{
	t_stack	*aux;

	if (size_stack(head) < 2)
		return (0);
	aux = (*head)->next;
	(*head)->next = (*head)->next->next;
	aux->next = (*head);
	(*head) = aux;
	if (print)
		ft_printf("sa\n");
	return (1);
}

int	swap_b(t_stack **head, int print)
{
	t_stack	*aux;

	if (size_stack(head) < 2)
		return (0);
	aux = (*head)->next;
	(*head)->next = (*head)->next->next;
	aux->next = (*head);
	(*head) = aux;
	if (print)
		ft_printf("sb\n");
	return (1);
}

void	swap_ab(t_stack **head_a, t_stack **head_b)
{
	if (swap_a(head_a, 0) || swap_b(head_b, 0))
		ft_printf("ss\n");
}
