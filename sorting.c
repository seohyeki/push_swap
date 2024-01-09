/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:06:58 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/09 21:21:41 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chage_value_to_index(t_stack *stack)
{
	int		i;
	t_list	*curr;
	
	curr = stack->top_a;
	while (curr)
	{
		i = 0;
		while (1)
		{
			if (curr->value == stack->arr[i])
				break;
			i++;
		}
		curr->value = i;
		curr = curr->next;
	}
}

void	three_elements(t_stack *stack)
{
	if (sort_check(stack->top_a))
		return ;
	if (stack->top_a->value > stack->top_a->next->value)
	{
		if (stack->top_a->value < stack->bottom_a->value) //2 1 3
			sa(stack);
		else if (stack->top_a->next->value < stack->bottom_a->value) //3 1 2
		 	ra(stack);
		else //3 2 1
		{
			sa(stack);
			rra(stack);
		}
	}
	else
	{
		rra(stack); //2 3 1
		if (stack->top_a->value > stack->top_a->next->value) //1 3 2
			sa(stack);
	}
}

void	five_elements(t_stack *stack)
{
	int		pivot;

	pivot = stack->size_a / 2;
	while (stack->size_a > 3)
	{
		if (stack->top_a->value < pivot)
			pb(stack);
		else
			ra(stack);
	}
	three_elements(stack);
	if (stack->size_b > 1)
	{
		if (stack->top_b->value < stack->top_b->next->value)
			sb(stack);
	}
	while (stack->size_b > 0)
		pa(stack);
}

void	sorting(t_stack *stack)
{
	chage_value_to_index(stack);
	if (stack->size_a == 2)
		sa(stack);
	else if (stack->size_a == 3)
		three_elements(stack);
	else if (stack->size_a == 4 || stack->size_a == 5)
		five_elements(stack);
	else
		greedy(stack);
}
