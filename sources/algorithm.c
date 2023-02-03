/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:21:50 by revieira          #+#    #+#             */
/*   Updated: 2023/02/03 19:03:19 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isSort(t_stack **header)
{
	t_stack	*aux;
	int		save_num;

	aux = (*header);
	save_num = aux->data;
	while (aux->next)
	{
		aux = aux->next;
		if (save_num > aux->data)
			return (0);
		save_num = aux->data;
	}
	return (1);
}

void	three_numbers(t_data *data)
{
	while (!ft_isSort(a))
	{
		if ((*a)->data > (*a)->next->data)
			exec_operation("sa", data);
		else
			exec_operation("rra", data);
	}
}
