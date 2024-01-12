/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:42:24 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/12 15:13:37 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstlast_prev(t_list *lst)
{
	if (lst)
	{
		while (lst->next->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
