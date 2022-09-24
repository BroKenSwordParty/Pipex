/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:05:20 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/18 14:10:10 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	size_t	i;

	if (!s)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dst)
		return (0);
	i = -1;
	while (s[++i])
		dst[i] = f(i, s[i]);
	dst[i] = '\0';
	return (dst);
}
