/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 07:30:05 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/05 16:36:08 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;
	size_t	s;

	c = -1;
	s = ft_strlen(src);
	if (dstsize)
	{
		while (src[++c] && --dstsize)
			dst[c] = src[c];
		dst[c] = '\0';
	}
	return (s);
}
