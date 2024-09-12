/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:19:37 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/28 12:57:42 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	success;

	if (!*to_find)
		return (str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == *to_find)
		{
			j = -1;
			success = 0;
			while (to_find[++j] && str[i + j])
			{
				if (to_find[j] != str[i + j])
					success = 0;
				success = 1;
			}
			if (success)
				return (&str[i]);
		}
	}
	return (NULL);
}
