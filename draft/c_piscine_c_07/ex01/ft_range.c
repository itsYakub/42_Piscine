/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:34:33 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 12:43:28 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (NULL);
	tab = (int *) malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (min < max)
	{
		tab[i++] = min++;
	}
	return (tab);
}

// #include <stdio.h>

// int main() {
// 	int min = -2137;
// 	int max = 2137;
// 	int *tab = ft_range(min, max);
// 	for(int i = 0; i < max - min; i++) {
// 		printf("%i ", tab[i]);
// 	}
// 	printf("\n");
// }