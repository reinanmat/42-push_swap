/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:33:40 by revieira          #+#    #+#             */
/*   Updated: 2023/02/16 17:05:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return(num);
}

int	get_small_cust(t_stack **s_b)
{
	t_stack	*tmp_b;
	int		cost;
	int		small_cost;
	int		save_cost;

	tmp_b = (*s_b);
	small_cost = 999999999;
	while (tmp_b)
	{
		cost = ft_abs(tmp_b->curr_pos) + ft_abs(tmp_b->target_pos);
		if (cost < small_cost)	
		{
			small_cost = cost;
			save_cost = tmp_b->idx;
		}
		tmp_b = tmp_b->next;
	}
	return (save_cost);	
}

void	exec_small_cost(t_stack **s_a, t_stack **s_b, int idx)
{
	t_stack	*tmp_b;

	tmp_b = (*s_b);
	while (tmp_b->idx != idx)
		tmp_b = tmp_b->next;
	while (tmp_b->curr_pos)
	{
		exec_operation("rb", NULL, s_b);
		tmp_b->curr_pos--;
	}
	while (tmp_b->target_pos)
	{
		exec_operation("ra", s_a, NULL);
		tmp_b->target_pos--;
	}
	exec_operation("pa", s_a, s_b);
}
