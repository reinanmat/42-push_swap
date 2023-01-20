/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_oper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:59:38 by revieira          #+#    #+#             */
/*   Updated: 2023/01/20 18:24:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(t_stack **head, int print)
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
	if (print)
		ft_printf("rra\n");
	return (1);
}

int	reverse_rotate_b(t_stack **head, int print)
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
	if (print)
		ft_printf("rrb\n");
	return (1);
}

void	reverse_rotate_ab(t_stack **head_a, t_stack **head_b)
{
	if (reverse_rotate_a(head_a, 0) || reverse_rotate_b(head_b, 0))
		ft_printf("rrr\n");
}
