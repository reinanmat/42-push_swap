/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:10:23 by revieira          #+#    #+#             */
/*   Updated: 2023/01/25 15:50:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stack **head, int print)
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
	if (print)
		ft_printf("ra\n");
	return (1);
}

int	rotate_b(t_stack **head, int print)
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
	if (print)
		ft_printf("rb\n");
	return (1);
}

void	rotate_ab(t_stack **head_a, t_stack **head_b)
{
	int	returns;

	returns = 0;
	returns += rotate_a(head_a, 0);
	returns += rotate_b(head_b, 0);
	if (returns)
		ft_printf("rr\n");
}
