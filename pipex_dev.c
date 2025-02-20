/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_dev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:07:43 by vpirotti          #+#    #+#             */
/*   Updated: 2025/02/19 12:07:43 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	printer(char **a)
{
	int	i;

	i = 0;
	while (a[i])
	{
		ft_printf("%s\n", a[i]);
		i++;
	}
}