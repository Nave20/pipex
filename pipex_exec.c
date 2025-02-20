/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:49:54 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/19 12:49:54 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "pipex.h"

void	cmd_one(char *path, char **cmd, char **env, int *cdt)
{
	char	*tmp;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		close(cdt[0]);
		close(cdt[1]);
		return (perror(NULL));
	}
	else if (pid == 0)
	{
		close(cdt[0]);
		dup2(cdt[1], 1);
		close(cdt[1]);
		execve(path, cmd, env);
	}
	else
	{
		close(cdt[1]);
		dup2(cdt[0], 0);
		close(cdt[0]);
	}
}

void	cmd_two(char *path, char **cmd, char **env, int fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (perror(NULL));
	else if (pid == 0)
	{
		dup2(fd, 1);
		execve(path, cmd, env);
	}
	else
		return ;
}

int		servo(char **path, char **argv, char **env)
{
	int		output;
	int		conduit[2];
	char	*tmp;
	char	**cmd;

	file_input(argv[1]);
	output = file_input(argv[4]);
	if (pipe(conduit) == -1)
		return (perror(NULL), -1);
	cmd_manager_one(path, argv, env, conduit);
	return (0);
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
// 	caramel =
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
