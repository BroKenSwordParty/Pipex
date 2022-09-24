/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:57:50 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/15 11:19:47 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	c;

	c = 0;
	if (!dst && !src)
		return (0);
	if (dst > src)
		return (ft_memcpy(dst, src, len));
	else
		while (len--)
			*(char *)(dst + c++) = *(char *)src++;
	return (dst);
}
