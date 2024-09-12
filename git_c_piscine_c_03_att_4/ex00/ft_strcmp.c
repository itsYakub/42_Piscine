/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:11 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/02 09:15:07 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (result == 0)
	{
		if (s1[i] > s2[i])
			result = s1[i] - s2[i];
		else if (s2[i] > s1[i])
			result = s1[i] - s2[i];
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (result);
}

// #include <stdio.h>
// #include <string.h>
// 
// int main() {
// 	printf("%i\n", strcmp("PISCINE", "PISCINE42", 8));
// 	printf("%i\n", ft_strcmp("PISCINE", "PISCINE42", 8));
// 	
// 	printf("%i\n", strcmp("HELLO WORLD", "Hello World", 7));
// 	printf("%i\n", ft_strcmp("HELLO WORLD", "Hello World", 7));
// 	
// 	printf("%i\n", 
//		strcmp(
//			"NULL POINTER", 
//			"NULL POINTER DEREFERENCING", 
//			16
//		)
//	);
// 	printf("%i\n", 
//		ft_strcmp(
//			"NULL POINTER", 
//			"NULL POINTER DEREFERENCING", 
//			16
//		)
//	);
// }