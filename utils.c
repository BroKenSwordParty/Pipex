/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:26:54 by jchamorr          #+#    #+#             */
/*   Updated: 2022/07/28 12:38:50 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	error_type(int err)
{
	if (err == 1)
		ft_putendl_fd (PIPE_ERROR, 1);
	if (err == 2)
		ft_putendl_fd (PIPE_ERROR, 1);
	

}