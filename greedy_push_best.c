/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_push_best.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:51:45 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 15:04:35 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_all(t_stack *stack, int *index_a, int *index_b)
{
	while (*index_a && *index_b && (*index_a > 0 && *index_b > 0))
	{
		rr(stack);
		(*index_a)--;
		(*index_b)--;
	}
	while (*index_a && *index_b && (*index_a < 0 && *index_b < 0))
	{
		rrr(stack);
		(*index_a)++;
		(*index_b)++;
	}
}

static void	rotate_a(t_stack *stack, int *index_a)
{
	while (*index_a)
	{
		if (*index_a > 0)
		{
			ra(stack);
			(*index_a)--;
		}
		else
		{
			rra(stack);
			(*index_a)++;
		}
	}
}

static void	rotate_b(t_stack *stack, int *index_b)
{
	while (*index_b)
	{
		if (*index_b > 0)
		{
			rb(stack);
			(*index_b)--;
		}
		else
		{
			rrb(stack);
			(*index_b)++;
		}
	}
}

void	push_best(t_stack *stack, int *index_a, int *index_b)
{
	rotate_all(stack, index_a, index_b);
	rotate_a(stack, index_a);
	rotate_b(stack, index_b);
	pa(stack);
}
