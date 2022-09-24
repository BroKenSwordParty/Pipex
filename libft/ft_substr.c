/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:40:58 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/16 13:14:50 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	while (s)
	{
		if (start > ft_strlen(s))
			return (ft_strdup(""));
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		dst = (char *)malloc(sizeof(char) * len + 1);
		if (!dst)
			return (0);
		ft_strlcpy(dst, &s[start], len + 1);
		return (dst);
	}
	return (0);
}
