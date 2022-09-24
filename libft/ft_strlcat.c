/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:28:29 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/11 18:25:44 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	s;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	c = 0;
	s = ft_strlen(dst);
	while (src[c] != '\0' && s + 1 < dstsize)
	{
		dst[s] = src[c];
		c++;
		s++;
	}
	dst[s] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[c]));
}
