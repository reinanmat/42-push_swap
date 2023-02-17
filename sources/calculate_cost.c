/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:33:40 by revieira          #+#    #+#             */
/*   Updated: 2023/02/17 17:17:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_small_cost(t_stack **s_a, t_stack **s_b, int idx)
{
	t_stack	*tmp_b;

	tmp_b = (*s_b);
	while (tmp_b->idx != idx)
		tmp_b = tmp_b->next;
	if (tmp_b->cost_a < 0 && tmp_b->cost_b < 0)
	{
		while (tmp_b->cost_a < 0 && tmp_b->cost_b < 0)
		{
			exec_operation("rrr", s_a, s_b);
			tmp_b->cost_a++;
			tmp_b->cost_b++;
		}
	}
	if (tmp_b->cost_a > 0 && tmp_b->cost_b > 0)
	{
		while (tmp_b->cost_a > 0 && tmp_b->cost_b > 0)
		{
			exec_operation("rr", s_a, s_b);
			tmp_b->cost_a--;
			tmp_b->cost_b--;
		}
	}
	while (tmp_b->cost_a < 0)
	{
		exec_operation("rra", s_a, NULL);
		tmp_b->cost_a++;
	}
	while (tmp_b->cost_a > 0)
	{
		exec_operation("ra", s_a, NULL);
		tmp_b->cost_a--;
	}
	while (tmp_b->cost_b < 0)
	{
		exec_operation("rrb", NULL, s_b);
		tmp_b->cost_b++;
	}
	while (tmp_b->cost_b > 0)
	{
		exec_operation("rb", NULL, s_b);
		tmp_b->cost_b--;
	}
	exec_operation("pa", s_a, s_b);
}
