/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_oper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:46:37 by revieira          #+#    #+#             */
/*   Updated: 2023/01/19 19:05:41 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *aux_b;
    t_stack *aux_a;

    aux_a = (*stack_a);
    aux_b = (*stack_b);
    aux_b->next = aux_a;
    (*stack_a) = aux_b;
    (*stack_b) = aux_a->next;
}
