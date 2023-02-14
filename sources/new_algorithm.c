/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:27:15 by revieira          #+#    #+#             */
/*   Updated: 2023/02/14 18:28:55 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	middle_stack(t_stack **stack)
{
	t_stack	*aux;
	int		i;
	int 	middle;

	i = 0;
	aux = (*stack);
	middle = size_stack(stack) / 2;
	while (i < middle)
	{
		aux = aux->next;
		i++;
	}
	return (aux->number);
}

void	update_pos_in_stack(t_stack *stack)
{
	t_stack	*aux;
	int		i;

	aux = stack;
	i = 0;
	while (aux)
	{
		aux->pos = i;
		aux = aux->next;
		i++;
	}
}

void	calculate_target_pos(t_stack **a, t_stack **b)
{
	t_stack *a_aux;
	t_stack	*b_aux;

	b_aux = (*b);
	while (b_aux)
	{
		a_aux = (*a);
		b_aux->tag_pos = 0;
		while (a_aux)
		{
			if (b_aux->idx == a_aux->idx + 1)
				b_aux->tag_pos = a_aux->pos;
			a_aux = a_aux->next;
		}
		b_aux = b_aux->next;
	}
}

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


int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return(num);
}

int	get_small_cust(t_stack **b)
{
	t_stack	*tmp_b;
	int		cost;
	int		small_cost;
	int		save_cost;

	tmp_b = (*b);
	small_cost = 99999;
	while (tmp_b)
	{
		cost = ft_abs(tmp_b->pos) + ft_abs(tmp_b->tag_pos);
		if (cost < small_cost)	
		{
			small_cost = cost;
			save_cost = tmp_b->idx;
		}
		tmp_b = tmp_b->next;
	}
	return (save_cost);	
}

void	exec_small_cost(t_stack **a, t_stack **b, int idx)
{
	t_stack	*tmp_b;

	tmp_b = (*b);
	if (tmp_b->idx == idx)
	{
		while (tmp_b->pos != 0)
		{
			exec_operation("ra", a, NULL);
			tmp_b->pos--;
		}
		while (tmp_b->tag_pos)
		{
			exec_operation("rb", NULL, b);
			tmp_b->tag_pos--;
		}
		exec_operation("pa", a, b);
	}
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

		update_pos_in_stack(a);
		update_pos_in_stack(b);
		calculate_target_pos(&a, &b);
		cost = get_small_cust(&b);
		exec_small_cost(&a, &b, cost);
	}
	update_pos_in_stack(a);
	update_pos_in_stack(b);
	calculate_target_pos(&a, &b);
	/*update_pos_in_stack(a);
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
	ft_print_stack(a);
	ft_print_stack(b);
}
