/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:48:32 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/25 19:10:16 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lines(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		i++;
	}
	return (i);
}

char	*ft_split_2(const char *s, size_t st, size_t fi)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (fi - st + 1));
	if (!dst)
		return (NULL);
	while (st < fi)
		dst[i++] = s[st++];
	dst[i] = '\0';
	return (dst);
}

char	**ft_fill(char **dst, const char *s, char c)
{
	size_t	i;
	size_t	p1;
	size_t	st;

	i = 0;
	p1 = 0;
	st = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || i == ft_strlen(s))
				dst[p1++] = ft_split_2(s, st, i);
		}
		while (s[i] == c && s[i])
		{
			i++;
			st = i;
		}
	}
	dst[p1] = NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;

	if (!s)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (ft_lines(s, c) + 1));
	if (!dst)
		return (NULL);
	ft_fill(dst, s, c);
	return (dst);
}
