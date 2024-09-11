/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:24:11 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/04 11:24:12 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// typedef struct s_stock_str
// {
// int size;
// char *str;
// char *copy;
// } t_stock_str;

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

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*src)
	{
		dest[i] = *(src++);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_create_str_tab(t_stock_str *result, int len, char *str)
{
	result->size = len;
	result->str = (char *) malloc(result->size * sizeof(char));
	if (!result->str)
		return (0);
	result->copy = (char *) malloc(result->size * sizeof(char));
	if (!result->copy)
		return (0);
	result->str = ft_strcpy(result->str, str);
	result->copy = ft_strcpy(result->copy, str);
	return (1);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			index;

	result = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (!result)
		return (NULL);
	index = -1;
	while (++index < ac)
	{
		if (!ft_create_str_tab(&result[index], ft_strlen(av[index]), av[index]))
			return (NULL);
	}
	if (!ft_create_str_tab(&result[ac], ft_strlen("\0"), "\0"))
		return (NULL);
	return (result);
}

// #include <stdio.h>

// int main() {
// 	char* text[2] = { "Hello", "World!" };

// 	t_stock_str* stock_str = ft_strs_to_tab(2, text);
// 	for(int i = 0; i < 2; i++) {
// 		printf(
// 			"str: %i\n> size: %i\n> str: %s\n> copy: %s\n",
// 			i + 1,
// 			stock_str[i].size,
// 			stock_str[i].str,
// 			stock_str[i].copy
// 		);
// 	}
// }
