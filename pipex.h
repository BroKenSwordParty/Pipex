/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:27:12 by jchamorr          #+#    #+#             */
/*   Updated: 2022/07/28 12:37:37 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/wait.h>

# define ARG_ERROR "Invalid arguments"
# define PIPE_ERROR "An error ocurred opening the pipe"

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid;
}				t_pipex;


#endif