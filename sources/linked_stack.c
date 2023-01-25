/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:42:05 by revieira          #+#    #+#             */
/*   Updated: 2023/01/25 15:50:49 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->data = data;
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

void	add_to_stack(t_stack **stack, int data)
{
	t_stack	*new;

	if (!*stack)
		*stack = new_node(data);
	else
	{
		new = new_node(data);
		add_node_back(stack, new);
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
