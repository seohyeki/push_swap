/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:59:19 by seohyeki          #+#    #+#             */
/*   Updated: 2023/12/26 18:05:59 by seohyeki         ###   ########.fr       */
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
		stack->top_a = tmp;
		stack->bottom_a = prev;
		write(1, "rra\n", 4);
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
		stack->top_b = tmp;
		stack->bottom_b = prev;
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack *stack)
{
	rra(stack);
	rrb(stack);
	if (stack->size_a > 1 || stack->size_b > 1)
		write(1, "rrr\n", 4);
}