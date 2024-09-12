/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:26:49 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/28 12:54:30 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (str[result] != '\0')
	{
		result++;
	}
	return (result);
}

int	ft_strnlen(char *str, unsigned int n)
{
	int	result;

	result = 0;
	while (result < n && *str)
	{
		str++;
		result++;
	}
	return (result);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int	i;

	i = 0;
	while (i < (int) size - 1)
	{
		if (*src)
		{
			*dest++ = *src++;
			i++;
		}
	}
	*dest = '\0';
	return (ft_strlen(src) + i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	slen;
	int	dlen;

	slen = ft_strlen(src);
	dlen = ft_strnlen(dest, size);
	if (dlen == size)
		return (dlen + slen);
	return (dlen + ft_strlcpy(dest + dlen, src, size - dlen));
}
