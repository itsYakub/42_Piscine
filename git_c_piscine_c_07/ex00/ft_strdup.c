/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:24:43 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 12:33:47 by joleksia         ###   ########.fr       */
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

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	result = (char *) malloc(ft_strlen(src) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*src != '\0')
		result[i++] = *(src++);
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>

// int main() {
// 	char* str = ft_strdup("Hello");
// 	printf("%s\n", str);
// 	free(str);
// }