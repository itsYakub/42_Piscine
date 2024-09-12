/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:39:41 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/11 16:39:43 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_scanff(void)
{
	int		count;
	char	current_char;
	char	buff[5000];
	char	*str;

	count = 0;
	while (read(0, &current_char, 1))
	{
		if(current_char == '\n')
		{
			return (NULL);
		}
		buff[count++] = current_char;
	}
	buff[count] = 0;
	str = malloc((count + 1) * sizeof(char));
	count = -1;
	while (buff[++count])
		str[count] = buff[count];
	str[count] = 0;
	return (str);
}
