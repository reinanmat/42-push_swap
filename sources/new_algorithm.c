/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:27:15 by revieira          #+#    #+#             */
/*   Updated: 2023/02/17 12:22:47 by revieira         ###   ########.fr       */
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

void	new_algorithm(t_stack *a, t_stack *b)
{
	int	middle_idx;
	int	cost;

	middle_idx = size_stack(&a) / 2;
	while (size_stack(&a) != 3)
	{
		if (a->idx >= middle_idx && has_smaller_idx_on_the_stack(&a, middle_idx))
			exec_operation("ra", &a, NULL);
		else
			exec_operation("pb", &a, &b);	
	}
	three_numbers(&a);
	while (size_stack(&b))
	{
		calculate_target_pos(&a, &b);
		cost = get_small_cust(&b);
//		ft_print_stack(a);
//		ft_print_stack(b);
//		ft_printf("%d\n", cost);
		exec_small_cost(&a, &b, cost);
	}
//	ft_print_stack(a);
//	ft_print_stack(b);
	while (a->idx != 1)
		exec_operation("ra", &a, NULL);
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
//	ft_print_stack(a);
//	ft_print_stack(b);
}
