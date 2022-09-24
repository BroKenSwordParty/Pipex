/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:23:49 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/12 13:51:03 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	if (n == 0)
		return (0);
	c = 0;
	while (c < n)
	{
		if (s1[c] && s1[c] == s2[c])
		{
			while (s1[c] && s1[c] == s2[c] && c < n)
				c++;
		}
		else
			return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
	}
	return (0);
}
