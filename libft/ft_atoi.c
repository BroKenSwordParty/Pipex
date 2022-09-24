/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:08:56 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/16 16:44:32 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		neg;
	long	num;

	neg = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			neg = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		num = (*str++ - 48) + (num * 10);
		if ((num * neg < -2147483648) || (num * neg > 2147483648))
			return ((num * neg < -2147483648) - 1);
	}
	return (num * neg);
}
