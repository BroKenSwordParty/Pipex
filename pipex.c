/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:46:49 by jchamorr          #+#    #+#             */
/*   Updated: 2022/07/28 12:49:44 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

/*
	Crea una "PIPE | " (canal de datos unidireccional) para comunicar procesos
	devuelve dos FD
*/


/*
	1. Comprobamos el nº de args
	2. Pasamos el FD por el pipe { fd[0] - Read ---- fd[1] - Write }

	   The array pipefd is used to
       return two file descriptors referring to the ends of the pipe.
       pipefd[0] refers to the read end of the pipe.  pipefd[1] refers
       to the write end of the pipe.  Data written to the write end of
       the pipe is buffered by the kernel until it is read from the read
       end of the pipe.  For further details, see pipe(7).
*/
int	main(int ac, char **av, char **env)
{
	t_pipex	*s;

	if (ac == 5)
	{
		if(pipe(s->fd) == -1)
			error_type(1);
		s->pid = fork();
		if (s->pid == -1)
			error_type(2);
		{
			/* code */
		}

	}
	else
		ft_putendl_fd(ARG_ERROR, 1);
	return (0);
}