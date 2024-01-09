/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:35 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/09 20:54:50 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print(t_stack *stack)
{
	// //배열
	// printf("==================================\n");
	// printf("arr: ");
	// int j = 0;
	// while (stack->arr[j])
	// {
	// 	printf("%d ", stack->arr[j]);
	// 	j++;
	// }
	// printf("\n");
	//stack a
	printf("==================================\n");
	printf("[stack A]\n");
	t_list *tmp = stack->top_a;
	while (tmp)
	{
		printf("%d(score: %d) -> ", tmp->value, tmp->score);
		tmp = tmp->next;
	}
	printf("NULL\n");
	printf("stack_a size: %d\n", stack->size_a);
	if (stack->top_a)
	{
		printf("stack_a top: %d\n", (stack->top_a)->value);
		printf("stack_a bottom: %d\n", (stack->bottom_a)->value);
	}
	printf("==================================\n");
	//stack b
	if (stack->top_b != NULL)
	{
		printf("[stack B]\n");
		t_list *tmp2 = stack->top_b;
		while (tmp2)
		{
			printf("%d(score: %d) -> ", tmp2->value, tmp2->score);
			tmp2 = tmp2->next;
		}
		printf("NULL\n");
		printf("stack_b size: %d\n", stack->size_b);
		if (stack->top_b)
		{
			printf("stack_b top: %d\n", (stack->top_b)->value);
			printf("stack_b bottom: %d\n", (stack->bottom_b)->value);
		}
		printf("==================================\n");
	}
}

int	dup_check(t_list *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	fill_stack(char **argv, t_stack *stack)
{
	char		**num_arr;
	long long	value;
	int			i;
	int			j;

	i = 0;
	while (argv[++i])
	{
		num_arr = ft_split(argv[i], ' ');
		if (num_arr == NULL)
			exit(1);
		j = 0;
		while (num_arr[j])
		{
			value = ft_atoi(num_arr[j]);
			if (value > 2147483647 || dup_check(stack->top_a, (int)value))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			ft_lstadd_back(&(stack->top_a), (int)value);
			j++;
		}
		ft_free_arr(num_arr);
	}
}

void	init_stack(t_stack *stack, char **argv)
{
	//stack a copy 초기화
	stack->arr = NULL;
	//stack_b 초기화
	stack->top_b = NULL;
	stack->bottom_b = NULL;
	stack->size_b = 0;
	//stack_a 초기화
	fill_stack(argv, stack); //stack_a만들기
	stack->bottom_a = ft_lstlast(stack->top_a);
	stack->size_a = ft_lstsize(stack->top_a);
}

void	linked_list_copy(t_stack *stack)
{
	int	i;
	t_list *curr;

	stack->arr = (int *)malloc(sizeof(int) * stack->size_a);
	if (stack->arr == NULL)
		exit(1);
	i = 0;
	curr = stack->top_a;
	while (i < stack->size_a)
	{
		stack->arr[i] = curr->value;
		curr = curr->next;
		i++;
	}
	quick_sort(stack->arr, 0, stack->size_a - 1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 1)
	{
		init_stack(&stack, argv); //stack 초기화
		if (sort_check(stack.top_a)) //이미 정렬되어있음. free 후 종료
		{
			ft_free_stack(&stack);
			return (0);
		}
		linked_list_copy(&stack); //리스트를 copy한 배열을 만들고 정렬하기
		sorting(&stack); //정렬하기
		//print(&stack);
	}
	ft_free_stack(&stack);
	//system("leaks a.out");
	return (0);
}
