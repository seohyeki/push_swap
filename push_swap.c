/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:35 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 15:07:22 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack->arr = NULL;
	stack->top_b = NULL;
	stack->bottom_b = NULL;
	stack->size_b = 0;
	fill_stack(argv, stack);
	stack->bottom_a = ft_lstlast(stack->top_a);
	stack->size_a = ft_lstsize(stack->top_a);
}

void	linked_list_copy(t_stack *stack)
{
	int		i;
	t_list	*curr;

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
		init_stack(&stack, argv);
		if (sort_check(stack.top_a))
		{
			ft_free_stack(&stack);
			return (0);
		}
		linked_list_copy(&stack);
		sorting(&stack);
		ft_free_stack(&stack);
	}
	return (0);
}
