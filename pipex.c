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
	char	**path;
	char	**cmd;

	if (argc != 5)
		return (write(2, "Error\n", 6), 0);
	path = get_path(env);
	servo(path, argv, env);

	// cmd = get_cmd(argv[2]);
	// exec(paths, cmd, env);
	// cmd = get_cmd(argv[3]);
	// exec2(paths, cmd, env);
	ft_printf("done");
	cleaner(path);
	return (0);
}