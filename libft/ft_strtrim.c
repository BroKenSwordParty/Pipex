/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:38:13 by jchamorr          #+#    #+#             */
/*   Updated: 2021/11/17 12:32:48 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;

	while (s1 && set)
	{
		while (*s1 && ft_strchr(set, *s1))
				s1++;
		i = ft_strlen(s1);
		while (i && ft_strchr(set, s1[i]))
			i--;
		return (ft_substr(s1, 0, i + 1));
	}
	return (0);
}
