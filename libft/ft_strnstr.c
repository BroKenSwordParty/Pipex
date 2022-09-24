/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:22:47 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/11 18:30:47 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (!*n)
		return ((char *)h);
	while (h[x])
	{
		y = 0;
		while (h[x + y] == n[y] && (x + y) < len)
		{
			if (n[y + 1] == '\0')
				return ((char *)&h[x]);
			y++;
		}
		x++;
	}
	return (0);
}
