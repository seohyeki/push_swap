# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 15:04:26 by seohyeki          #+#    #+#              #
#    Updated: 2024/01/12 14:22:43 by seohyeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
SRCS =	./utils/ft_atoi.c \
		./utils/ft_free_all.c \
		./utils/ft_lstadd_back.c \
		./utils/ft_lstlast_prev.c \
		./utils/ft_lstlast.c \
		./utils/ft_lstsize.c \
		./utils/ft_split.c \
		./utils/ft_strlen.c \
		./utils/ft_sort_check.c \
		./command/swap.c \
		./command/push.c \
		./command/reverse.c \
		./command/rotate.c \
		quick_sort.c \
		push_swap.c \
		sorting.c \
		greedy.c \
		greedy_find_best.c \
		greedy_push_best.c
OBJS =	$(SRCS:.c=.o)
CFLAGS =	-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	cc $(CFLAGS) -o $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : 
	make fclean
	make all

.PHONY: all clean fclean re
