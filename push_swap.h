/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:04:24 by seohyeki          #+#    #+#             */
/*   Updated: 2023/12/22 16:23:53 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	int				size_a;
	struct s_list	*top_a;
	struct s_list	*bottom_a;
	int 			size_b;
	struct s_list	*top_b;
	struct s_list	*bottom_b;
}	t_stack;

/*libft*/
int			ft_strlen(const char *s);
long long	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, int value);
int			ft_lstsize(t_list *lst);

/*free*/
void		ft_free_all(char **arr, t_list *stack);
void		ft_free_arr(char **arr);
void		ft_free_stack(t_list *stack);

/*command*/
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

#endif
