/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/24 17:56:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack **stack, int wanted)
{
	t_stack	*aux;

	aux = (*stack);
	while (aux)
	{
		if (aux->idx == wanted)
			break ;
		aux = aux->next;
	}
	return (aux->curr_pos);
}

void	put_value_in_top(t_stack **s_a, int index, int pos)
{
	int	size;

	size = size_stack(s_a);
	if ((*s_a)->idx == index)
		return ;
	if (pos > size / 2)
	{
		while (pos < size)
		{
			exec_operation("rra", s_a, NULL);
			pos++;
		}
	}
	else
	{
		while (pos != 0)
		{
			exec_operation("ra", s_a, NULL);
			pos--;
		}
	}
}

void	sort_three_numbers(t_stack **s_a)
{
	while (!ft_issort(s_a))
	{
		if ((*s_a)->idx > (*s_a)->next->idx)
			exec_operation("sa", s_a, NULL);
		else
			exec_operation("rra", s_a, NULL);
	}
}

void	sort_four_numbers(t_stack **s_a, t_stack **s_b)
{
	int	pos_low;

	pos_low = find_index(s_a, 1);
	put_value_in_top(s_a, 0, pos_low);
	if (ft_issort(s_a))
		return ;
	exec_operation("pb", s_a, s_b);
	sort_three_numbers(s_a);
	exec_operation("pa", s_a, s_b);
}

void	sort_five_numbers(t_stack **s_a, t_stack **s_b)
{
	int	pos_low;
	int	pos_high;

	pos_low = find_index(s_a, 1);
	put_value_in_top(s_a, 0, pos_low);
	if (ft_issort(s_a))
		return ;
	exec_operation("pb", s_a, s_b);
	set_pos(*s_a);
	pos_high = find_index(s_a, 5);
	put_value_in_top(s_a, 5, pos_high);
	exec_operation("pb", s_a, s_b);
	sort_three_numbers(s_a);
	exec_operation("pa", s_a, s_b);
	exec_operation("ra", s_a, s_b);
	exec_operation("pa", s_a, s_b);
}
