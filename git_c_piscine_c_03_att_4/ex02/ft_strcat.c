/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:35:52 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/02 09:33:49 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strcat(char *dest, char *src)
{
	int	strlen_dest;
	int	i;

	strlen_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[strlen_dest + i] = src[i];
		i++;
	}
	dest[strlen_dest + i] = '\0';
	return (dest);
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
// 	printf("%s\n", strcat(dest1, src1));
// 	printf("%s\n", ft_strcat(dest2, src2));
// }