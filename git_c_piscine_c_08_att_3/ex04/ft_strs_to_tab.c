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
#include "ft_stock_str.h"

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
		result[index].size = ft_strlen(av[index]);
		result[index].str = av[index];
		result[index].copy = ft_strdup(av[index]);
	}
	result[ac].size = 0;
	result[ac].str = 0;
	result[ac].copy = 0;
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
