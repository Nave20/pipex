/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:49:54 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/20 17:30:32 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "pipex.h"

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	path_error(void)
{
	perror("\033[31mcommand not found");
	exit(EXIT_FAILURE);
}

void	execution(char *argv, char **env)
{
	char	**cmd;
	char	**paths;
	char	*r_path;

	paths = get_path(env);
	if (!paths)
		return ;
	cmd = get_cmd(argv);
	if (!cmd)
		return (cleaner(paths));
	r_path = path_finder2(paths, cmd[0]);
	if (!r_path)
	{
		cleaner(paths);
		return (cleaner(cmd));
	}
	cleaner(paths);
	if (execve(r_path, cmd, env) == -1)
	{
		cleaner(cmd);
		free(r_path);
		perror("execve");
		exit(127);
	}
}

void	cmd_1(char **argv, char **env, int *fd)
{
	int	infile;

	close(fd[0]);
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		return (error());
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[1]);
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(infile);
	execution(argv[2], env);
}

void	cmd_2(char **argv, char **env, int *fd)
{
	int	outfile;

	close(fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		return (error());
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[0]);
	if (dup2(outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(outfile);
	execution(argv[3], env);
}
