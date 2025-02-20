/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:25:02 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/20 17:34:59 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_input(char	*name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	// dup2(fd, 0);
	return (fd);
}

int	file_output(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC);
	return (fd);
}