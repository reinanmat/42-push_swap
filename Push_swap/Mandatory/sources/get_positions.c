/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:14:39 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 17:38:56 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middle_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		middle;

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

void	set_pos(t_stack *stack)
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

int	find_high_idx(t_stack **stack)
{
	t_stack	*tmp;
	int		high;

	tmp = *stack;
	high = tmp->idx;
	while (tmp)
	{
		if (tmp->idx > high)
			high = tmp->idx;
		tmp = tmp->next;
	}
	return (high);
}

int	get_approximate_highest_idx(t_stack **stack, int idx)
{
	t_stack	*tmp;
	int		close_high;

	close_high = find_high_idx(stack);
	tmp = *stack;
	while (tmp)
	{
		if (tmp->idx < close_high && idx < tmp->idx)
			close_high = tmp->idx;
		tmp = tmp->next;
	}
	return (close_high);
}

void	calculate_target_pos(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		appr_high;

	set_pos(*s_a);
	set_pos(*s_b);
	tmp_b = (*s_b);
	while (tmp_b)
	{
		tmp_a = (*s_a);
		appr_high = get_approximate_highest_idx(s_a, tmp_b->idx);
		while (tmp_a->idx != appr_high)
			tmp_a = tmp_a->next;
		if (appr_high > tmp_b->idx)
			tmp_b->target_pos = tmp_a->curr_pos;
		else if (tmp_a->curr_pos + 1 >= size_stack(s_a))
			tmp_b->target_pos = 0;
		else
			tmp_b->target_pos = tmp_a->curr_pos + 1;
		tmp_b = tmp_b->next;
	}
}
