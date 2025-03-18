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

void	execution(char *argv, char **env)
{
	char	**cmd;
	char	**paths;
	char	*r_path;

	paths = get_path(env);
	cmd = get_cmd(argv);
	r_path = path_finder(paths, cmd[0]);
	cleaner(paths);
	execve(r_path, cmd, env);
}

void	cmd_1(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		return;
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	execution(argv[2], env);
}

void	cmd_2(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		return;
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execution(argv[3], env);
}

// void	exec(char **path, char **cmd, char **env)
// {
// 	char	*tmp;
// 	int		prout[2];
// 	pid_t	pid;
//
//
// 	if (pipe(prout) == -1)
// 		return;
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		close(prout[0]);
// 		close(prout[1]);
// 		return;
// 	}
// 	else if (pid == 0)
// 	{
// 		close(prout[0]);
// 		dup2(prout[1], 1);
// 		close(prout[1]);
// 		tmp = ft_strjoin(path[path_finder(path, cmd[0])], cmd[0]);
// 		execve(tmp, cmd, env);
// 	}
// 	else
// 	{
// 		close(prout[1]);
// 		dup2(prout[0], 0);
// 		close(prout[0]);
// 	}
// }
//
// void	exec2(char **path, char **cmd, char **env)
// {
// 	char	*tmp;
// 	int		caramel;
// 	pid_t	pid;
//
// 	caramel = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		return;
// 	}
// 	else if (pid == 0)
// 	{
// 		dup2(caramel, 1);
// 		tmp = ft_strjoin(path[path_finder(path, cmd[0])], cmd[0]);
// 		execve(tmp, cmd, env);
// 	}
// 	else
// 	{
// 		return;
// 	}
// }
