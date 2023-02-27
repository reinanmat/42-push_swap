/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:46:37 by revieira          #+#    #+#             */
/*   Updated: 2023/02/27 14:45:43 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push_a(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (size_stack(s_b) < 1)
		return (0);
	tmp = (*s_b)->next;
	(*s_b)->next = (*s_a);
	(*s_a) = (*s_b);
	(*s_b) = tmp;
	return (1);
}

int	push_b(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp;

	if (size_stack(s_a) < 1)
		return (0);
	tmp = (*s_a)->next;
	(*s_a)->next = (*s_b);
	(*s_b) = (*s_a);
	(*s_a) = tmp;
	return (1);
}
