/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:35:04 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/18 11:32:51 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long numb)
{
	int	len;

	len = 0;
	if (numb <= 0)
		len = 1;
	while (numb != 0)
	{
		numb = numb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*p;

	num = n;
	len = ft_intlen(num);
	p = (char *)malloc(sizeof(*p) * (1 + len));
	if (!p)
		return (0);
	p[len--] = '\0';
	if (num < 0)
	{
		*p = '-';
		num = -num;
	}
	if (num == 0)
		p[0] = '0';
	while (num > 0)
	{
		p[len] = (num % 10) + 48;
		num /= 10;
		len--;
	}
	return (p);
}
