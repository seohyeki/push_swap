/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:51:19 by seohyeki          #+#    #+#             */
/*   Updated: 2024/01/15 19:02:32 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str < '0' || '9' < *str)
		return (2147483648);
	while (*str)
	{
		if (*str < '0' || '9' < *str)
			return (2147483648);
		num = num * 10 + *str - '0';
		str++;
	}
	num = num * sign;
	if ((num > 2147483647 || num < -2147483648))
		return (2147483648);
	else
		return (num);
}

static int	ft_count_word(char const *str, char sep)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != sep)
		{
			while (1)
			{
				if (str[i] == sep || str[i] == '\0')
				{
					count++;
					break ;
				}
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_dup(char const *str, char sep)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (str[i] != sep && str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_free_str(char **strs, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static void	make_strs(char **strs, char const *str, char c, int size)
{
	int	i;

	i = 0;
	while (*str && i < size)
	{
		while (*str == c && *str != '\0')
			str++;
		strs[i] = ft_dup(str, c);
		if (strs[i] == NULL)
		{
			ft_free_str(strs, i + 1);
			strs = NULL;
		}
		while (*str != c && *str != '\0')
			str++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		size;
	int		i;

	i = 0;
	size = ft_count_word(s, c);
	if (size == 0)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	strs = (char **)malloc(sizeof(char *) * (size + 1));
	if (strs == NULL)
		return (NULL);
	strs[size] = 0;
	make_strs(strs, s, c, size);
	return (strs);
}
