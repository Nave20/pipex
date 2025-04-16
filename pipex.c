/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:25:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/18 13:25:36 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		mfd[2];
	int		status;
	pid_t	mpid[2];

	status = 0;
	if (argc == 5)
	{
		if (pipe(mfd) == -1)
			return (0);
		mpid[0] = fork();
		if (mpid[0] == -1)
			return (0);
		if (mpid[0] == 0)
			cmd_1(argv, env, mfd);
		mpid[1] = fork();
		if (mpid[1] == -1)
			return (-1);
		if (mpid[1] == 0)
			cmd_2(argv, env, mfd);
		close(mfd[1]);
		close(mfd[0]);
		if (waitpid(mpid[0], &status, 0) < 0)
			exit(EXIT_FAILURE);
		if (waitpid(mpid[1], &status, 0) < 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		write(2, "Error, wrong input. Should be as follow :\n", 42);
		write(2, "infile cmd1 cmd2 outfile  \n", 28);
	}
	return (status);
}
