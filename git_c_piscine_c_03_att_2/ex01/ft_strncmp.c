/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:31:10 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/27 15:06:44 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (result == 0 && i < (int) n)
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
