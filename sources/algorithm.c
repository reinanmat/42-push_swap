/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:50 by revieira          #+#    #+#             */
/*   Updated: 2023/01/25 17:59:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	high_num(t_stack **a)
{
	t_stack	*aux;
	int		high_num;

	aux = (*a);
	high_num = aux->data;
	while (aux->next)
	{
		aux = aux->next;
		if (aux->data > high_num)
			high_num = aux->data;
	}
	if (high_num == (*a)->data)
		return (1);
	else if (high_num == (*a)->next->data)
		return (2);
	else
		return (3);
}

int	low_num(t_stack **a)
{
	t_stack	*aux;
	int		low_num;

	aux = (*a);
	low_num = aux->data;
	while (aux->next)
	{
		aux = aux->next;
		if (aux->data < low_num)
			low_num = aux->data;
	}
	if (low_num == (*a)->data)
		return (1);
	else if (low_num == (*a)->next->data)
		return (2);
	else
		return (3);
}

void	three_numbers(t_stack **a)
{
	int	pos_high;
	int	pos_low;

	pos_high = high_num(a);
	pos_low = low_num(a);
	if (pos_high == 2 && pos_low == 1)
	{
		swap_a(a, 1);
		rotate_a(a, 1);
	}
	else if (pos_high == 1)
	{
		if (pos_low == 3)
		{
			swap_a(a, 1);
			reverse_rotate_a(a, 1);
		}
		else
			rotate_a(a, 1);
	}
	else if (pos_high == 3)
		swap_a(a, 1);
	else
		reverse_rotate_a(a, 1);
}
