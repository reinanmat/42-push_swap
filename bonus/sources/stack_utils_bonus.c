/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:05 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 14:14:00 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*new_node(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->number = number;
	new->next = NULL;
	return (new);
}

void	add_node_back(t_stack **head_stack, t_stack *new)
{
	t_stack	*aux;

	aux = *head_stack;
	while (aux->next)
		aux = aux->next;
	aux->next = new;
}

void	add_to_stack(t_stack **head_stack, int number)
{
	t_stack	*new;

	if (!*head_stack)
		*head_stack = new_node(number);
	else
	{
		new = new_node(number);
		add_node_back(head_stack, new);
	}
}

int	size_stack(t_stack **stack)
{
	t_stack	*aux;
	int		size;

	size = 0;
	aux = (*stack);
	while (aux)
	{
		aux = aux->next;
		size++;
	}
	return (size);
}

void	free_stack(t_stack **head_stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!head_stack)
		return ;
	current = *head_stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head_stack = NULL;
}
