/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:43:52 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 15:21:22 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = (int *) malloc((max - min) * sizeof(int));
	if (!*range)
		return (-1);
	i = -1;
	while (++i < max - min)
	{
		range[0][i] = min + i;
	}
	return (max - min);
}

// #include <stdio.h>

// int main() {
// 	int min = -42;
// 	int max = 42;
// 	int *range;
// 	printf("Range: %i\n", ft_ultimate_range(&range, min, max));
// 	for(int i = 0; i < max - min; i++) {
// 		printf("%i ", range[i]);
// 	}
// 	printf("\n");
// }