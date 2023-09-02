/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:29:23 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 17:36:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_small_cost(t_stack **s_b)
{
	t_stack	*tmp_b;
	int		cost;
	int		small_cost;
	int		save_idx;

	tmp_b = (*s_b);
	small_cost = ft_abs(tmp_b->cost_b) + ft_abs(tmp_b->cost_a);
	save_idx = tmp_b->idx;
	while (tmp_b)
	{
		cost = ft_abs(tmp_b->cost_b) + ft_abs(tmp_b->cost_a);
		if (cost < small_cost)
		{
			small_cost = cost;
			save_idx = tmp_b->idx;
		}
		tmp_b = tmp_b->next;
	}
	return (save_idx);
}

static int	cost_to_stack_a(t_stack *s_a, int target_pos)
{
	int	cost;

	cost = target_pos;
	if (target_pos > size_stack(&s_a) / 2)
		cost = (target_pos - size_stack(&s_a));
	return (cost);
}

static int	cost_to_stack_b(t_stack *s_b, int pos)
{
	int	cost;

	cost = pos;
	if (pos > size_stack(&s_b) / 2)
		cost = (pos - size_stack(&s_b));
	return (cost);
}

void	calculate_cost(t_stack **s_a, t_stack **s_b)
{
	t_stack	*tmp_b;

	tmp_b = (*s_b);
	while (tmp_b)
	{
		tmp_b->cost_a = cost_to_stack_a((*s_a), tmp_b->target_pos);
		tmp_b->cost_b = cost_to_stack_b((*s_b), tmp_b->curr_pos);
		tmp_b = tmp_b->next;
	}
}
