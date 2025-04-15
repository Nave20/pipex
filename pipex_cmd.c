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
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
		i++;
	}
	if (!env[i])
		return (path_error(), NULL);
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
	return (error(), NULL);
}
