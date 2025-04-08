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

	//  char	**cmd;
	//  char	**paths;
	//  char	*r_path;
	//
	// paths = get_path(env);
	// if (!paths)
	// 	return (0);
	// printer(paths);
	// cmd = get_cmd(argv[2]);
	// printer(paths);
	// cleaner(paths);
	// ft_printf(path_finder2(paths, cmd[0]));
	// r_path = path_finder2(paths, cmd[0]);
	// ft_printf(r_path);

	if (argc == 5)
	{
		if (pipe(mfd) == -1)
			return 0;
		mpid = fork();
		if (mpid == -1)
			return 0;
		if (mpid == 0)
			cmd_1(argv, env, mfd);
		waitpid(mpid, &status, 0);
		cmd_2(argv, env, mfd);
	}
	else
	{
		write(2, "Error, wrong input. Should be as follow :\n", 42);
		write(2, "infile cmd1 cmd2 outfile  \n", 28);
	}
	return (0);
}