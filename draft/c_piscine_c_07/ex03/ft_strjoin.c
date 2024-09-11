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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		rlen;
	int		result_index;
	int		str_element;
	int		sep_index;

	if (size <= 0)
	{
		result = (char *) malloc(1 * sizeof(char));
		*result = '\0';
		return (result);
	}
	rlen = ft_strslen(strs, size) + ft_strlen(sep) * (size - 1);
	result = (char *) malloc(rlen * sizeof(char));
	result_index = 0;
	str_element = -1;
	while (result_index != rlen && ++str_element < size)
	{
		while (*strs[str_element])
			result[result_index++] = *(strs[str_element])++;
		sep_index = -1;
		while (str_element < size - 1 && 0 < size - 1 && sep[++sep_index])
			result[result_index++] = sep[sep_index];
	}
	result[result_index] = '\0';
	return (result);
}

// #include <stdio.h>

// int main() {
// 	char* strs[] = { "Hello", "World!", "More", "Wooooords!" };
// 	char* str = ft_strjoin(4, strs, " ");

// 	printf("%s\n", str);

// 	free(str);
// }
