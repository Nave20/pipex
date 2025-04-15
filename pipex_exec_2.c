/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:33:05 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/15 09:33:05 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_two(char **argv, char **env, int mfd[2], int *status)
{
	pid_t	mpid;

	mpid = fork();
	if (mpid == -1)
		return (-1);
	if (mpid == 0)
		cmd_2(argv, env, mfd);
	return (0);
}
