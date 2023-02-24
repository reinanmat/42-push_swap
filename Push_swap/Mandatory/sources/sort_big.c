/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:27:15 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 17:45:03 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_in_stack(t_stack **stack, int idx)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->idx == idx)
			return (tmp->curr_pos);
		tmp = tmp->next;
	}
	return (-1);
}

int	has_small_in_stack(t_stack **stack, int idx)
{	
	t_stack	*aux;

	aux = (*stack)->next;
	while (aux)
	{
		if (aux->idx < idx)
			return (1);
		aux = aux->next;
	}
	return (0);
}

void	send_to_stack_b(t_stack **s_a, t_stack **s_b)
{
	int	middle;

	middle = size_stack(s_a) / 2;
	while (size_stack(s_a) != 3)
	{
		if ((*s_a)->idx >= middle && has_small_in_stack(s_a, middle))
			exec_operation("ra", s_a, NULL);
		else
			exec_operation("pb", s_a, s_b);
	}
}

void	exec_rotate_or_reverse_rotate(t_stack **s_a)
{	
	set_pos(*s_a);
	if (find_in_stack(s_a, 1) <= size_stack(s_a) / 2)
		while ((*s_a)->idx != 1)
			exec_operation("ra", s_a, NULL);
	else
		while ((*s_a)->idx != 1)
			exec_operation("rra", s_a, NULL);
}

void	sort_all(t_stack **s_a, t_stack **s_b)
{
	int	cost;

	send_to_stack_b(s_a, s_b);
	sort_three_numbers(s_a);
	while (size_stack(s_b))
	{
		calculate_target_pos(s_a, s_b);
		calculate_cost(s_a, s_b);
		cost = get_small_cost(s_b);
		exec_small_cost(s_a, s_b, cost);
	}
	exec_rotate_or_reverse_rotate(s_a);
}
