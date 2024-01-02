/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:06:58 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/02 14:52:24 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_mid_value(t_stack *stack)
{
	int	tmp;
	int	size;
	int	i;

	size = stack->size_a;
	while (size > 1)
	{
		i = 0;
		while (i + 1 < size)
		{
			if (stack->arr[i] > stack->arr[i + 1])
			{
				tmp = stack->arr[i];
				stack->arr[i] = stack->arr[i + 1];
				stack->arr[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
	if (stack->size_a % 2 == 1)
		return (stack->arr[stack->size_a / 2]);
	else
		return (stack->arr[(stack->size_a / 2) - 1]);
}

void	five_elements(t_stack *stack)
{
	int		pivot;

	pivot = find_mid_value(stack);
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
	if (stack->size_a == 2)
		sa(stack);
	else if (stack->size_a == 3)
		three_elements(stack);
	else if (stack->size_a <= 5)
		five_elements(stack);
	else
		sort_elements(stack);
}
