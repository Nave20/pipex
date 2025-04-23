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

char	**get_path(char **env, int i, int a)
{
	char	**output;
	char	*ptr;

	while (env[++a] != NULL)
	{
		if (ft_strnstr(env[a], "PATH=", 5))
			break ;
	}
	if (!env || !env[a])
		return (path_error(), NULL);
	output = ft_split(&env[a][5], ':');
	if (!output)
		return (NULL);
	while (output[++i])
	{
		ptr = output[i];
		output[i] = ft_strjoin(output[i], "/");
		if (!output[i])
		{
			output[i] = ptr;
			return (cleaner(output), NULL);
		}
		free(ptr);
	}
	return (output);
}

char	**get_cmd(char *str)
{
	char	**output;

	if (!str)
		return (NULL);
	output = ft_split(str, ' ');
	return (output);
}

char	*path_finder2(char **paths, char *cmd)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strjoin(paths[0], cmd);
	if (access(tmp, X_OK) == 0)
		return (tmp);
	while (paths[i])
	{
		free(tmp);
		tmp = ft_strjoin(paths[i], cmd);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		i++;
	}
	free(tmp);
	return (NULL);
}
