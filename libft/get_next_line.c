/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:50:54 by jchamorr          #+#    #+#             */
/*   Updated: 2022/05/27 12:40:02 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fliying_free(void *to_free)
{
	free(to_free);
	to_free = NULL;
}

char	*ft_rd(int fd, char *buff, char *stattik)
{
	ssize_t	rd_var;

	rd_var = 1;
	while (rd_var != '\0')
	{
		rd_var = read(fd, buff, BUFFER_SIZE);
		if (rd_var < 0)
			return (0);
		else if (rd_var == 0)
			return (stattik);
		buff[rd_var] = '\0';
		stattik = ft_strjoin(stattik, buff);
		if (ft_strchr(buff, '\n'))
			return (stattik);
	}
	return (stattik);
}

char	*ft_clean_static(char *line)
{
	size_t	i;
	char	*to_return;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (0);
	to_return = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*to_return == '\0')
		ft_fliying_free(to_return);
	line[i + 1] = '\0';
	return (to_return);
}

char	*get_next_line(int fd)
{
	static char	*stattik;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	line = ft_rd(fd, buff, stattik);
	ft_fliying_free(buff);
	if (!line)
		return (NULL);
	stattik = ft_clean_static(line);
	return (line);
}
