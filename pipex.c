/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:46:49 by jchamorr          #+#    #+#             */
/*   Updated: 2022/09/19 19:12:25 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	child_p(char **av, char **env, t_pipex *s)
{
	dup2(s->fd[1], STDOUT_FILENO);
	close(s->fd[0]);
	dup2(s->in, STDIN_FILENO);
	s->args = ft_split(av[2], ' ');
	if (command(s, s->args[0]) == 0)
		error_type(4);
	close_fds(s);
	execve (s->cmd, s->args, env);
}

void	parent_p(char **av, char **env, t_pipex *s)
{
	dup2(s->fd[0], STDIN_FILENO);
	close(s->fd[1]);
	dup2(s->out, STDOUT_FILENO);
	s->args = ft_split(av[3], ' ');
	if (command(s, s->args[0]) == 0)
		error_type(4);
	execve (s->cmd, s->args, env);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	s;

	if (ac == 5)
	{
		s.in = open(av[1], O_RDONLY);
		s.out = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (s.in < 0 || s.out < 0)
			error_type(3);
		if (pipe(s.fd) == -1)
			error_type(1);
		s.paths = pathfinder(env);
		s.cmd_list = ft_split(s.paths, ':');
		s.pid = fork();
		if (s.pid == -1)
			error_type(2);
		if (s.pid == 0)
			child_p(av, env, &s);
		parent_p(av, env, &s);
		waitpid(s.pid, NULL, 0);
		fliying_free(&s);
	}
	else
		ft_putendl_fd(ARG_ERROR, 1);
	return (0);
}
