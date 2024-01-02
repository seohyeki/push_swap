/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:35:25 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/02 14:41:40 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_stack(t_stack *stack)
{
	t_list	*tmp;

	while (stack->top_a)
	{
		tmp = stack->top_a;
		stack->top_a = stack->top_a->next;
		free(tmp);
	}
	free(stack->arr);
}
