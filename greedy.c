/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:10:53 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/09 21:21:58 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_all_stack_b(t_stack *stack)
{
	int	pivot_large;
	int	pivot_small;
	int	first_value;

	pivot_small = stack->size_a / 3; //작은 피봇
	pivot_large = (stack->size_a / 3) * 2; //큰 피봇
	first_value = stack->bottom_a->value;
	while (1)
	{
		if (pivot_large < stack->top_a->value)
			ra(stack);
		else if (pivot_small < stack->top_a->value)
			pb(stack);
		else
		{
			pb(stack);
			rb(stack);
		}
		if (stack->top_a->value == first_value)
			break;
	}
	while (stack->size_a > 3)
		pb(stack);
	three_elements(stack);
}

void	find_min_max_stack_a(t_stack *stack, int *min, int *max)
{
	t_list	*stack_a;

	*min = stack->top_a->value;
	*max = stack->top_a->value;
	stack_a = stack->top_a;
	while (stack_a)
	{
		if (stack_a->value < *min)
			*min = stack_a->value;
		if (stack_a->value > *max)
			*max = stack_a->value;
		stack_a = stack_a->next;
	}
}

int find_index_a(t_stack *stack, int value)
{
	int index;
	int	min;
	int max;
	t_list *stack_a;
	
	index = 0;
	find_min_max_stack_a(stack, &min, &max);
	stack_a = stack->top_a;
	if (value < min) //pa하려는 수가 stack a에서 가장 작을 수 일때
	{
		if (stack_a->value == min) //첫번째가 가장 작은 값일때
			return (index);
		while (stack_a)
		{
			index++;
			if (stack_a->value == min)
				break;
			stack_a = stack_a->next;
		}
		if (index < stack->size_a / 2)
			return (index - 1);
		else
			return (((stack->size_a - index) * -1) - 1);
	}
	else if (max < value)
	{
		while (stack_a)
		{
			index++;
			if (stack_a->value == max)
				break;
			stack_a = stack_a->next;
		}
		return (index);
	}
	while (stack_a->next)
	{
		index++;
		if (stack_a->value < value && value < stack_a->next->value)
			break;
		stack_a = stack_a->next;
	}
	if (stack_a->next == NULL)
	{
		if (stack_a->value < value && value < stack->top_a->value)
			index = 0;
	}
	if (index < stack->size_a / 2)
		return (index);
	else
		return (index - stack->size_a);
}

void	find_min_score_value(t_stack *stack, int *min_score_a, int *min_score_b)
{
	t_list	*stack_b;
	int		min_score;
	int		score_a;
	int		score_b;
	int		index;

	index = 0;
	stack_b = stack->top_b;
	while (stack_b)
	{
		//stack b 움직이는 횟수 계산
		if (index >= stack->size_b / 2)
		{
			stack_b->score = (stack->size_b - index);
			score_b = index - stack->size_b;
		}
		else
		{
			stack_b->score = index;
			score_b = index;
		}

		//stack a 움직이는 횟수 계산
		score_a = find_index_a(stack, stack_b->value);
		if (score_a < 0)
			stack_b->score += (score_a * -1);
		else
			stack_b->score += score_a;
		
		//현재 노드가 더 적게 움직이는지 확인하기
		if (index == 0 || stack_b->score < min_score)
		{
			min_score = stack_b->score;
			*min_score_a = score_a;
			*min_score_b = score_b;
		}
		
		//다음 노드 계산하러 넘어가기
		stack_b = stack_b->next;
		index++;
	}
}

void	push(t_stack *stack, int *index_a, int *index_b)
{
	//stack a, b 같이 움직이기
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
		
	//stack a 움직이기
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

	//stack b 움직이기
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
	pa(stack);	
}

void	make_top_a_zero(t_stack *stack)
{
	int		index_zero;
	t_list	*curr;

	index_zero = 0;
	curr = stack->top_a;
	while (curr->value != 0)
	{
		index_zero++;
		curr = curr->next;
	}
	if (index_zero < stack->size_a / 2)
	{
		while (stack->top_a->value != 0)
			ra(stack);
	}
	else
	{
		while (stack->top_a->value != 0)
			rra(stack);
	}
		
}

void	greedy(t_stack *stack)
{
	int		index_a;
	int		index_b;
	
	//1. value를 정렬된 인덱스로 바꾸기	
	//2. pivot(전체 갯수/2)기준으로 모두 stack b로 넘기기
	push_all_stack_b(stack);
	
	while (stack->size_b > 0)
	{
		index_a = 0;
		index_b = 0;
		//3. b에서 a로 넘어올때 가장 적게 움직이는 노드 찾기
		find_min_score_value(stack, &index_a, &index_b);
		//3-1. rb와 rrb횟수 구하기
		//3-2. ra와 rra횟수 구하기
		//4. 실제로 이동하기
		//printf("index_a: %d, index_b: %d\n", index_a, index_b);
		push(stack, &index_a, &index_b);
		//print(stack);
	}
	
	//5. value가 0인 노드가 a의 top으로 오게 만들기
	make_top_a_zero(stack);
}
