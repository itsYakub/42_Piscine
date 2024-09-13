/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:58:30 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/12 10:58:32 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_atoi(char *str)
{
	int	result;
	int	is_negative;

	result = 0;
	is_negative = -1;
	while (*str < 32)
	        str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = 10 * result - (*str++ - '0');
	return (result * is_negative);
}

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (str[result])
	{
		result++;
	}
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	result = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*src != '\0')
		result[i++] = *(src++);
	result[i] = '\0';
	return (result);
}

int ft_error(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	return (1);
}
