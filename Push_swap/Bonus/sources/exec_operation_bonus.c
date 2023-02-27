/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:04:38 by revieira          #+#    #+#             */
/*   Updated: 2023/02/27 14:45:09 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	swap_operations(char *oper, t_stack **s_a, t_stack **s_b)
{
	int	func_ret;

	func_ret = 0;
	if (!ft_strcmp(oper, "sa"))
		func_ret = swap_a(s_a);
	else if (!ft_strcmp(oper, "sb"))
		func_ret = swap_b(s_b);
	else if (!ft_strcmp(oper, "ss"))
	{
		func_ret = swap_a(s_a);
		func_ret = swap_b(s_b);
	}
	return (func_ret);
}

static int	push_operations(char *oper, t_stack **s_a, t_stack **s_b)
{
	int	func_ret;

	func_ret = 0;
	if (!ft_strcmp(oper, "pa"))
		func_ret = push_a(s_a, s_b);
	else if (!ft_strcmp(oper, "pb"))
		func_ret = push_b(s_a, s_b);
	return (func_ret);
}

static int	rotate_operations(char *oper, t_stack **s_a, t_stack **s_b)
{
	int	func_ret;

	func_ret = 0;
	if (!ft_strcmp(oper, "ra"))
		func_ret = rotate_a(s_a);
	else if (!ft_strcmp(oper, "rb"))
		func_ret = rotate_b(s_b);
	else if (!ft_strcmp(oper, "rr"))
	{
		func_ret = rotate_a(s_a);
		func_ret = rotate_b(s_b);
	}
	else if (!ft_strcmp(oper, "rra"))
		func_ret = reverse_rotate_a(s_a);
	else if (!ft_strcmp(oper, "rrb"))
		func_ret = reverse_rotate_b(s_b);
	else if (!ft_strcmp(oper, "rrr"))
	{
		func_ret = reverse_rotate_a(s_a);
		func_ret = reverse_rotate_b(s_b);
	}
	return (func_ret);
}

void	exec_operation(char *oper, t_stack **s_a, t_stack **s_b)
{
	int	func_ret;

	func_ret = 0;
	if (*oper == 's')
		func_ret = swap_operations(oper, s_a, s_b);
	else if (*oper == 'p')
		func_ret = push_operations(oper, s_a, s_b);
	else if (*oper == 'r')
		func_ret = rotate_operations(oper, s_a, s_b);
	if (func_ret)
		ft_printf("%s\n", oper);
}
