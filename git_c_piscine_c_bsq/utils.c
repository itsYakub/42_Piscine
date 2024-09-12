/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:22:20 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/11 12:51:12 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_atoi(char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result - (*str++ - '0');
	}
	return (result * -1);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b * -1;
	*b = temp;
}

int	ft_strlen(char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

int	ft_logerr(char *err)
{
	write(STDERR_FILENO, err, ft_strlen(err));
	return (1);
}

int	get_line_len(char *file_str, int i)
{
	int	len;

	len = 0;
	while (file_str[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}
