/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:19:37 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/02 13:35:40 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (result == 0 && i < (int) n)
	{
		result = *s1 - *s2;
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		i++;
		s1++;
		s2++;
	}
	return (result);
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

char	*ft_strstr(char *str, char *to_find)
{
	int	strlen_to_find;

	strlen_to_find = ft_strlen(to_find);
	if (!strlen_to_find)
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, to_find, strlen_to_find) == 0)
			return (str);
		str++;
	}
	return ((void *) 0);
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     char str1[16] = "Hello, World!";
//     char substr1[16] = "Hi";
//     printf("%s\n", strstr(str1, substr1));
//     printf("%c\n", *strstr(str1, substr1));
//     printf("%x\n", strstr(str1, substr1));

//     printf("%s\n", ft_strstr(str1, substr1));
//     printf("%c\n", *ft_strstr(str1, substr1));
//     printf("%x\n", ft_strstr(str1, substr1));

//     return 0;
// }