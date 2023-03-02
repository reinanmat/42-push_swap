/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:38 by revieira          #+#    #+#             */
/*   Updated: 2023/02/28 19:48:12 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	swap_operations(char *oper, t_stack **s_a, t_stack **s_b)
{
	if (!ft_strcmp(oper, "sa"))
		swap_a(s_a);
	else if (!ft_strcmp(oper, "sb"))
		swap_b(s_b);
	else if (!ft_strcmp(oper, "ss"))
	{
		swap_a(s_a);
		swap_b(s_b);
	}
}

static void	push_operations(char *oper, t_stack **s_a, t_stack **s_b)
{
	if (!ft_strcmp(oper, "pa"))
		push_a(s_a, s_b);
	else if (!ft_strcmp(oper, "pb"))
		push_b(s_a, s_b);
}

static void	rotate_operations(char *oper, t_stack **s_a, t_stack **s_b)
{
	if (!ft_strcmp(oper, "ra"))
		rotate_a(s_a);
	else if (!ft_strcmp(oper, "rb"))
		rotate_b(s_b);
	else if (!ft_strcmp(oper, "rr"))
	{
		rotate_a(s_a);
		rotate_b(s_b);
	}
	else if (!ft_strcmp(oper, "rra"))
		reverse_rotate_a(s_a);
	else if (!ft_strcmp(oper, "rrb"))
		reverse_rotate_b(s_b);
	else if (!ft_strcmp(oper, "rrr"))
	{
		reverse_rotate_a(s_a);
		reverse_rotate_b(s_b);
	}
}

static void	select_operation(char *oper, t_stack **s_a, t_stack **s_b)
{
	if (*oper == 's')
		swap_operations(oper, s_a, s_b);
	else if (*oper == 'p')
		push_operations(oper, s_a, s_b);
	else if (*oper == 'r')
		rotate_operations(oper, s_a, s_b);
}

void	exec_opers(t_opers **opers, t_stack **s_a, t_stack **s_b)
{
	t_opers	*tmp;

	tmp = *opers;
	while (tmp)
	{
		select_operation(tmp->operation, s_a, s_b);
		tmp = tmp->next;
	}
}
