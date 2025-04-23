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

int	last_slash(char *argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] == '/')
			j = i;
		i++;
	}
	return (j + 1);
}

void	exec_two(char *argv, char **env)
{
	char	**cmd;
	char	*path;
	char	*r_path;
	int		i;

	if (!*env)
		return (path_error());
	i = last_slash(argv);
	path = malloc(ft_strlen(argv) * sizeof(char));
	if (!path)
		return ;
	ft_strlcpy(path, argv, i + 1);
	cmd = get_cmd(&argv[i]);
	if (!cmd)
		return (free(path));
	r_path = ft_strjoin(path, cmd[0]);
	free(path);
	if (!r_path)
		return (cleaner(cmd));
	if (access(r_path, X_OK) != 0)
		error_two(r_path, cmd);
	if (execve(r_path, cmd, env) == -1)
		error_exit_one(cmd, r_path);
}

void	execution(char *argv, char **env)
{
	char	**cmd;
	char	**paths;
	char	*r_path;

	if (argv[0] == '/')
	{
		exec_two(argv, env);
		return ;
	}
	if (argv[0] == 0)
		exit(127);
	paths = get_path(env, 0, 0);
	if (!paths)
		return ;
	cmd = get_cmd(argv);
	if (!cmd)
		return (cleaner(paths));
	r_path = path_finder2(paths, cmd[0]);
	if (!r_path)
		error_three(paths, cmd);
	cleaner(paths);
	if (execve(r_path, cmd, env) == -1)
		error_exit_one(cmd, r_path);
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
