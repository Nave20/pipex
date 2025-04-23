/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:07:46 by vpirotti          #+#    #+#             */
/*   Updated: 2025/04/23 15:33:42 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	path_error(void)
{
	perror("\033[31mcommand not found");
	exit(EXIT_FAILURE);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	error_two(char *path, char **cmd)
{
	free(path);
	cleaner(cmd);
	exit(127);
}

void	error_three(char **path, char **cmd)
{
	cleaner(path);
	cleaner(cmd);
	ft_putendl_fd("\033[31mcommand not found", 2);
	exit(127);
}

void	cleaner(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
