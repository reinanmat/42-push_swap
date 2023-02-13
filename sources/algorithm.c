/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/13 17:46:57 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issort(t_stack **stack)
{
	t_stack	*aux;
	int		save_num;

	aux = (*stack);
	save_num = aux->number;
	while (aux->next)
	{
		aux = aux->next;
		if (save_num > aux->number)
			return (0);
		save_num = aux->number;
	}
	return (1);
}

int	find_index(t_stack **stack, int wanted)
{
	t_stack	*aux;
	int		pos;

	aux = (*stack);
	pos = 1;
	if (aux->index == wanted)
		return (pos);
	while (aux->next)
	{
		aux = aux->next;
		pos++;
		if (aux->index == wanted)
			break;
	}
	return (pos);
}

void	put_value_in_top(t_stack **a, int index, int pos)
{	
	int	size;

	size = size_stack(a);
	if ((*a)->index == index)
		return ;
	if (pos > size / 2)
	{
		while (pos <= size)
		{
			exec_operation("rra", a, NULL);
			pos++;
		}
	}
	else
	{
		while (pos != 1)
		{
			exec_operation("ra", a, NULL);
			pos--;
		}
	}
}

void	three_numbers(t_stack **stack)
{
	while (!ft_issort(stack))
	{
		if ((*stack)->index > (*stack)->next->index)
			exec_operation("sa", stack, NULL);
		else
			exec_operation("rra", stack, NULL);
	}
}

void	four_numbers(t_stack **a, t_stack **b)
{
	int	pos_low;

	pos_low = find_index(a, 0);
	ft_printf("%d\n", pos_low);
	put_value_in_top(a, 0, pos_low);
	if (ft_issort(a))
		return ;
	exec_operation("pb", a, b);
	three_numbers(a);
	exec_operation("pa", a, b);
}

void	five_numbers(t_stack **a, t_stack **b)
{
	int	pos_low;
	int	pos_high;

	pos_low = find_index(a, 0);
	put_value_in_top(a, 0, pos_low);
	if (ft_issort(a))
		return ;
	exec_operation("pb", a, b);
	pos_high = find_index(a, 4);
	put_value_in_top(a, 4, pos_high);
	exec_operation("pb", a, b);
	three_numbers(a);
	exec_operation("pa", a, b);
	exec_operation("ra", a, b);
	exec_operation("pa", a, b);
}
