/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:26:49 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/30 11:10:31 by joleksia         ###   ########.fr       */
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
	while (result < (int) n && *str)
	{
		str++;
		result++;
	}
	return (result);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char	*dest_start;
	char	*dest_end;
	char	*s;

	dest_start = dest;
	dest_end = dest + size;
	s = src;
	while (*s != '\0' && dest_start < dest_end)
		*dest_start++ = *s++;
	if (dest_start < dest_end)
		*dest_start = '\0';
	else if (size > 0)
		*dest_start-- = '\0';
	while (*s != '\0')
		s++;
	return (s - src);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	slen;
	int	dlen;

	slen = ft_strlen(src);
	dlen = ft_strnlen(dest, size);
	if (dlen == (int) size)
		return (dlen + slen);
	return (dlen + ft_strlcpy(dest + dlen, src, size - dlen));
}

// #include <stdio.h>
// #include <bsd/string.h>
// 
// int main() {
// 	char dest1[16] = "Hello, ";
// 	char src1[16] = "World!";
// 
// 	char dest2[16] = "Hello, ";
// 	char src2[16] = "World!";
// 
// 	printf("%zu\n", strlcat(dest1, src1, 2));
// 	printf("src: %s\n", src1);
// 	printf("dest: %s\n", dest1);
// 	
// 	printf("%u\n", ft_strlcat(dest2, src2, 2));
// 	printf("src: %s\n", src2);
// 	printf("dest: %s\n", dest2);
// }