/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:35 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/02 16:28:55 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//중복된 숫자인지 체크하기(중복이면 1, 아니면 0)
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

//정렬되어 있는지 확인하기(정렬 1, 아니면 0)
int	sort_check(t_list *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

//stack a 만들기
void	fill_stack(char **argv, t_stack *stack_a)
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
		j = -1;
		while (num_arr[++j])
		{
			value = ft_atoi(num_arr[j]);
			if (value > 2147483647 || dup_check(stack_a->top_a, (int)value))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			ft_lstadd_back(&(stack_a->top_a), (int)value);
		}
		stack_a->bottom_a = ft_lstlast(stack_a->top_a);
		stack_a->size_a = ft_lstsize(stack_a->top_a);
		ft_free_arr(num_arr);
	}
}

void	make_stack_arr(t_stack *stack)
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
}
#include <stdio.h>

void print(t_stack *stack)
{
	//배열
	printf("==================================\n");
	printf("arr: ");
	int j = 0;
	while (stack->arr[j])
	{
		printf("%d ", stack->arr[j]);
		j++;
	}
	printf("\n");
	//stack a
	printf("==================================\n");
	printf("[stack A]\n");
	t_list *tmp = stack->top_a;
	while (tmp)
	{
		printf("%d -> ", tmp->value);
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
			printf("%d -> ", tmp2->value);
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

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc > 1)
	{
		stack.top_b = NULL;
		stack.bottom_b = NULL;
		stack.size_b = 0;
		fill_stack(argv, &stack);
		if (stack.top_a == NULL || sort_check(stack.top_a) == 1) //malloc 실패, 정렬 됨
		{
			ft_free_stack(&stack);
			return (0);
		}
		make_stack_arr(&stack);
		sorting(&stack);

		print(&stack);
	}
	ft_free_stack(&stack);
	//system("leaks a.out");
	return (0);
}
