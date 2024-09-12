/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:31:10 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/02 13:35:53 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	result;

	result = 0;
	while (*s1 && *s2 && (*s1 == *s2) && n + 1)
	{
		n--;
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	else
		return (*s1 - *s2);
}

// #include <stdio.h>
// #include <string.h>
//
// int main() {
// 	printf("%i\n", strncmp("PISCINE", "PISCINE42", 32));
// 	printf("%i\n", ft_strncmp("PISCINE", "PISCINE42", 32));
//	
// 	printf("%i\n", strncmp("HELLO WORLD", "Hello World", 7));
// 	printf("%i\n", ft_strncmp("HELLO WORLD", "Hello World", 7));
//
// 	printf("%i\n", 
// 		strncmp(
// 			"NULL POINTER", 
// 			"NULL POINTER DEREFERENCING", 
// 			12
// 		)
// 	);
// 	printf("%i\n", 
// 		ft_strncmp(
// 			"NULL POINTER", 
// 			"NULL POINTER DEREFERENCING", 
// 			12
// 		)
// 	);
// }