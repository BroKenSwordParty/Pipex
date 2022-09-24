/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:26:54 by jchamorr          #+#    #+#             */
/*   Updated: 2022/09/19 19:19:43 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	fliying_free(t_pipex *s)
{
	int	i;

	i = 0;
	while (s->args[i])
	{
		free(s->args[i]);
		i++;
	}
	free(s->args);
	i = 0;
	while (s->cmd_list[i])
	{
		free(s->cmd_list[i]);
		i++;
	}
	free (s->cmd_list);
}

void	close_fds(t_pipex *s)
{
	close (s->in);
	close (s->out);
}

void	error_type(int err)
{
	if (err == 1)
		ft_putendl_fd(PIPE_ERROR, 2);
	if (err == 2)
		ft_putendl_fd(FORK_ERROR, 2);
	if (err == 3)
		ft_putendl_fd(FILE_ERROR, 2);
	if (err == 4)
		ft_putendl_fd(CMD_ERROR, 2);
	exit(1);
}

char	*pathfinder(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	command(t_pipex *s, char *cmd_1)
{
	int		i;

	i = 0;
	while (s->cmd_list[i])
	{
		s->cmd = ft_strjoin(ft_strjoin(s->cmd_list[i], "/"), cmd_1);
		if (access(s->cmd, 0) == 0)
			return (1);
		free(s->cmd);
		i++;
	}
	return (0);
}
