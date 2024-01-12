/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 17:47:55 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/09 16:01:00 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*ft_lstnew(int value)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst == NULL)
		return (NULL);
	new_lst->value = value;
	new_lst->next = 0;
	new_lst->score = 0;
	return (new_lst);
}

void	ft_lstadd_back(t_list **lst, int value)
{
	t_list	*last;
	t_list	*newnode;

	newnode = ft_lstnew(value);
	if (newnode == NULL)
		exit(1);
	if (*lst == NULL)
		*lst = newnode;
	else
	{
		last = ft_lstlast(*lst);
		last->next = newnode;
	}
}
