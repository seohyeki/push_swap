/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:12:32 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/02 16:13:36 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_elements(t_stack *stack)
{
	int		pivot;
	t_list	*curr;
	t_list	*tmp;

	pivot = find_mid_value(stack);
	//value를 인덱스로 바꾸기
	// int	i;
	// curr = stack->top_a;
	// while (curr)
	// {
	// 	i = 0;
	// 	while (stack->arr[i] != curr->value)
	// 		i++;
	// 	curr->value = i;
	// 	curr = curr->next;
	// }
	
	//모두 b로 보내기
	while (stack->top_a)
	{
		pb(stack);
		// if (stack->top_a->value > pivot)
		// 	pb(stack);
		// else
		// {
		// 	pb(stack);
		// 	rb(stack);
		// }
	}
	
	//어떤거를 a로 다시 보낼까? 모든요소의 움직이는 횟수 구하기
	curr = stack->top_a;
	while (curr)
	{
		//rb, rrb횟수 구하기(a로 가려면 top으로 가야 하니깐)
		
		//a로 넘어가서 정렬되려면 돌아야 하는 횟수
		
		if (curr->score < tmp->score) //가장 score가 작은 노드를 기억하기
			tmp = curr;
		curr = curr->next;
	}

	// if (/* 인덱스 < size_b/2 */)
	// {
	// 	while (stack->top_a != tmp)
	// 		rb(stack);
	// }
	// else
	// {
	// 	while(stack->top_a != tmp)
	// 		rrb(stack);
	// }
}
