/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:22:43 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 15:45:31 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_strslen(char **str, int size)
{
	int	result;

	result = 0;
	while (size--)
		result += ft_strlen(str[size]);
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*d;

	d = dest;
	dest += ft_strlen(dest);
	while (*src)
		*dest++ = *src++;
	*dest++ = '\0';
	return (d);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		rlen;
	int		str_element;

	if (size <= 0)
	{
		result = (char *) malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	rlen = ft_strslen(strs, size) + ft_strlen(sep) * (size - 1);
	result = (char *) malloc(rlen * sizeof(char));
	str_element = -1;
	while (++str_element < size)
	{
		ft_strcat(result, strs[str_element]);
		ft_strcat(result, sep);
	}
	result[rlen] = '\0';
	return (result);
}

// #include <stdio.h>

// int main() {
// 	char* strs[] = { "Hello", "World" };
// 	char* str = ft_strjoin(2, strs, " ");

// 	printf("%s\n", str);

// 	free(str);
// }
