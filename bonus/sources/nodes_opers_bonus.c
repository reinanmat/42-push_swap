/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_opers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:15:36 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 19:46:37 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	init_operations(char **valided_operations)
{
	valided_operations[0] = ft_strdup("sa\n");
	valided_operations[1] = ft_strdup("sb\n");
	valided_operations[2] = ft_strdup("ss\n");
	valided_operations[3] = ft_strdup("pa\n");
	valided_operations[4] = ft_strdup("pb\n");
	valided_operations[5] = ft_strdup("ra\n");
	valided_operations[6] = ft_strdup("rb\n");
	valided_operations[7] = ft_strdup("rr\n");
	valided_operations[8] = ft_strdup("rra\n");
	valided_operations[9] = ft_strdup("rrb\n");
	valided_operations[10] = ft_strdup("rrr\n");
	valided_operations[11] = NULL;
}

t_opers	*new_node_oper(char *operation)
{
	t_opers	*new;

	new = (t_opers *)malloc(sizeof(t_opers));
	new->operation = ft_strtrim(operation, "\n");
	new->next = NULL;
	return (new);
}

void	add_operation(t_opers **head, char *operation)
{
	t_opers	*new;
	t_opers	*aux;

	if (!*head)
		*head = new_node_oper(operation);
	else
	{
		new = new_node_oper(operation);
		aux = *head;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

int	size_opers(t_opers **head)
{
	t_opers	*aux;
	int		size;

	size = 0;
	aux = (*head);
	while (aux)
	{
		aux = aux->next;
		size++;
	}
	return (size);
}

void	free_operation(t_opers **head)
{
	t_opers	*current;
	t_opers	*next;

	if (!head)
		return ;
	current = *head;
	while (current)
	{
		next = current->next;
		free(current->operation);
		free(current);
		current = next;
	}
	*head = NULL;
}
