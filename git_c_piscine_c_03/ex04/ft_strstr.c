/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:19:37 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/27 10:13:20 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	success;

	i = 0;
	while (str[i])
	{
		if (str[i] == *to_find)
		{
			j = 0;
			success = 0;
			while (to_find[j] && str[i + j])
			{
				if (to_find[j] != str[i + j])
					success = 0;
				success = 1;
				j++;
			}
			if (success)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
