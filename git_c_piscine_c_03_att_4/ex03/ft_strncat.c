/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:13:24 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/30 10:07:29 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*d;

	d = dest;
	dest += ft_strlen(dest);
	while (nb && *src)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest++ = '\0';
	return (d);
}

// #include <stdio.h>
// #include <string.h>
// 
// int main() {
// 	char dest1[16] = "Hello, ";
// 	char src1[16] = "World!";
// 
// 	char dest2[16] = "Hello, ";
// 	char src2[16] = "World!";
// 
// 	printf("%s\n", strncat(dest1, src1, 6));
// 	printf("%s\n", ft_strncat(dest2, src2, 6));
// }
