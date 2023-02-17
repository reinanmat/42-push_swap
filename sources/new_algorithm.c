/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:27:15 by revieira          #+#    #+#             */
/*   Updated: 2023/02/17 18:46:08 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_smaller_idx_on_the_stack(t_stack **stack, int idx)
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

int	find_stack(t_stack **stack, int idx)
{
	t_stack *tmp;

	tmp = *stack;
	while(tmp)
	{
		if (tmp->idx == idx)
			return (tmp->curr_pos);
		tmp = tmp->next;
	}
	return (-1);
}

void	new_algorithm(t_stack **s_a, t_stack **s_b)
{
	int	middle_idx;
	int	cost;

	middle_idx = size_stack(s_a) / 2;
	while (size_stack(s_a) != 3)
	{
		if ((*s_a)->idx >= middle_idx && has_smaller_idx_on_the_stack(s_a, middle_idx))
			exec_operation("ra", s_a, NULL);
		else
			exec_operation("pb", s_a, s_b);	
	}
	three_numbers(s_a);
	while (size_stack(s_b))
	{
		calculate_target_pos(s_a, s_b);
		calculate_cost(s_a, s_b);
		cost = get_small_cust(s_b);
		exec_small_cost(s_a, s_b, cost);
	}
//	ft_print_stack(a);
//	ft_print_stack(b);
	if (find_stack(s_a, 1) >= size_stack(s_a))	
		while ((*s_a)->idx != 1)
			exec_operation("ra", s_a, NULL);
	else
		while ((*s_a)->idx != 1)
			exec_operation("rra", s_a, NULL);
	/*
	update_pos_in_stack(a);
	update_pos_in_stack(b);
	calculate_target_pos(&a, &b);
	update_pos_in_stack(a);
	  update_pos_in_stack(b);
	  calculate_target_pos(&a, &b);
	  ft_print_stack(a);
	  ft_print_stack(b);
	  cost = get_small_cust(&b);
	  ft_printf("%d\n", cost);
	  exec_small_cost(&a, &b, cost);
	  update_pos_in_stack(a);
	  update_pos_in_stack(b);
	  calculate_target_pos(&a, &b);*/
}
