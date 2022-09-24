/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:27:12 by jchamorr          #+#    #+#             */
/*   Updated: 2022/09/19 14:07:21 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>

# define ARG_ERROR "Invalid arguments\n"
# define PIPE_ERROR "An error ocurred opening the pipe\n"
# define FORK_ERROR "The creation of the process was unsuccessful\n"
# define FILE_ERROR "An error ocurred opening the FD\n"
# define CMD_ERROR "Command not found\n"

typedef struct s_pipex
{
	int		fd[2];
	int		in;
	int		out;
	pid_t	pid;
	char	*paths;
	char	**cmd_list;
	char	*cmd;
	char	**args;
}t_pipex;

int		command(t_pipex *s, char *cmd_1);
void	fliying_free(t_pipex *s);
void	close_fds(t_pipex *s);
void	error_type(int err);
void	free_struct(t_pipex *s);
char	*pathfinder(char **envp);
void	child_p(char **av, char **env, t_pipex *s);
void	parent_p(char **av, char **env, t_pipex *s);

#endif

// ./Pipex   File1   Command1  Command2    File2
//  av[0]    av[1]     av[2]    av[3]      av[4]