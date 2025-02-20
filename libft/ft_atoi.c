/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:57:47 by vpirotti          #+#    #+#             */
/*   Updated: 2024/11/06 17:57:47 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>

long	ft_atoi(const char *str, int *bool)
{
	long	sign;
	long	res;
	long	i;

	i = 0;
	sign = 1;
	res = 0;
	*bool = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
        if (res * 10 + (str[i] - 48) > INT_MAX)
          *bool = -1;
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
