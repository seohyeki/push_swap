/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:59:19 by seohyeki          #+#    #+#             */
/*   Updated: 2023/12/22 16:22:22 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack)
{
	t_list *tmp;
	t_list *prev;
	
	prev = stack->top_a;
	if (stack->size_a > 1)
	{
		while (prev->next->next != NULL)
			prev = prev->next;
		tmp = stack->bottom_a;
		tmp->next = stack->top_a;
		prev->next = NULL;
	}
}

void	rrb(t_stack *stack)
{
	t_list *tmp;
	t_list *prev;
	
	prev = stack->top_b;
	if (stack->size_b > 1)
	{
		while (prev->next->next != NULL)
			prev = prev->next;
		tmp = stack->bottom_b;
		tmp->next = stack->top_b;
		prev->next = NULL;
	}
}

void	rrr(t_stack *stack)
{
	t_list *tmp;
	t_list *prev;
	
	prev = stack->top_a;
	if (stack->size_a > 1)
	{
		while (prev->next->next != NULL)
			prev = prev->next;
		tmp = stack->bottom_a;
		tmp->next = stack->top_a;
		prev->next = NULL;
	}
	prev = stack->top_b;
	if (stack->size_b > 1)
	{
		while (prev->next->next != NULL)
			prev = prev->next;
		tmp = stack->bottom_b;
		tmp->next = stack->top_b;
		prev->next = NULL;
	}
}