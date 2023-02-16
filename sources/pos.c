/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:42:47 by revieira          #+#    #+#             */
/*   Updated: 2023/02/16 16:52:24 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middle_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int 	middle;

	i = 0;
	tmp = (*stack);
	middle = size_stack(stack) / 2;
	while (i < middle)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->number);
}

void	get_pos(t_stack *stack)
{
	int		pos;

	pos = 0;
	while (stack)
	{
		stack->curr_pos = pos;
		stack = stack->next;
		pos++;
	}
}


