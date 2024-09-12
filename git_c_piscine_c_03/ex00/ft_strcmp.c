/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:11 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/26 15:28:48 by joleksia         ###   ########.fr       */
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
			result = 1;
		else if (s2[i] > s1[i])
			result = -1;
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (result);
}
