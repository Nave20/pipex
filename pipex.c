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
	pid_t	mpid;

	if (argc == 5)
	{
		if (pipe(mfd) == -1)
			return (0);
		mpid = fork();
		if (mpid == -1)
			return (0);
		if (mpid == 0)
			cmd_1(argv, env, mfd);
		if (waitpid(mpid, &status, 0) > 0)

		fork_two(argv, env, mfd, &status);
	}
	else
	{
		write(2, "Error, wrong input. Should be as follow :\n", 42);
		write(2, "infile cmd1 cmd2 outfile  \n", 28);
	}
	return (status);
}
