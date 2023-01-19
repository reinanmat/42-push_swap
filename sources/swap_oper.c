/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:06:05 by revieira          #+#    #+#             */
/*   Updated: 2023/01/19 18:43:53 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack **head)    
{
    t_stack *aux;

    if (size_stack(head) < 2)
        return ;
    aux = (*head)->next;
    (*head)->next = (*head)->next->next;
    aux->next = (*head); 
    (*head) = aux;
}

void    swap_b(t_stack **head)
{
    t_stack *aux;

    if (size_stack(head) < 2)
        return ;
    aux = (*head)->next;
    (*head)->next = (*head)->next->next;
    aux->next = (*head); 
    (*head) = aux;
}

void    swap_ss(t_stack **head_a, t_stack **head_b)
{
    t_stack *aux_a;
    t_stack *aux_b;

    if (size_stack(head_a) < 2 || size_stack(head_b) < 2)
        return ;
    aux_a = (*head_a)->next;
    (*head_a)->next = (*head_a)->next->next;
    aux_a->next = (*head_a);
    aux_b = (*head_b)->next;
    (*head_b)->next = (*head_b)->next->next;
    aux_b->next = (*head_b);
    (*head_b) = aux_b;
}
