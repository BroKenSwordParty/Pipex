/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:31:40 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/02 18:46:06 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int i, size_t len)
{
	while (len)
		*(unsigned char *)(b + --len) = (unsigned char)i;
	return ((char *)b);
}
