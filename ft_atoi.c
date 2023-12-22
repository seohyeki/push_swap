/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 21:34:13 by seohyeki          #+#    #+#             */
/*   Updated: 2023/12/22 15:16:26 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

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
	if (!ft_isdigit(*str)) //+나 -만 들어왔을때
		return (2147483648);
	while (*str)
	{
		if (!ft_isdigit(*str)) //숫자 아님
				return (2147483648);
		num = num * 10 + *str - '0';
		str++;
	}
	num = num * sign;
	if ((num > 2147483647 || num < -2147483648)) //int범위 아님
		return (2147483648);
	else
		return (num);
}
