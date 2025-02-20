/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 09:25:36 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/20 17:36:11 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	**output;
	char	*ptr;
	int	i;

	i = 0;
	while (!ft_strnstr(env[i],"PATH=", 1000))
		i++;
	output = ft_split(&env[i][5], ':');
	i = 0;
	while (output[i])
	{
		ptr = output[i];
		output[i] = ft_strjoin(output[i], "/");
		free(ptr);
		i++;
	}
	return (output);
}

char	**get_cmd(char *str)
{
	char	**output;

	output = ft_split(&str[0], ' ');
	return (output);
}

char	*path_finder(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	i = 0;
	tmp = ft_strjoin(paths[0], cmd);
	while (access(tmp, X_OK) != 0)
	{
		i++;
		free(tmp);
		tmp = ft_strjoin(paths[i], cmd);
	}
	if (access(tmp, X_OK) != 0)
	{
		free(tmp);
		return (NULL);
	}
	else
		return (tmp);
}

void	cmd_manager_one(char **path, char **argv, char **env, int fd, int *cdt)
{
	char	*right_path;
	char	**cmd;

	cmd = get_cmd(argv[2]);
	right_path = path_finder(path, cmd[0]);
	cmd_one(right_path, cmd, env, fd, cdt);
	cleaner(cmd);
	free(right_path);
}

void	cmd_manager_two(char **path, char **argv, char **env, int *cdt)
{
	char	*right_path;
	char	**cmd;
	int		fd;

	cmd = get_cmd(argv[3]);
	right_path = path_finder(path, cmd[0]);
	cmd_two(right_path, cmd, env, argv, cdt);
	cleaner(cmd);
	free(right_path);
}