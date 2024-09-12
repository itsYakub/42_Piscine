/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:23:50 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/27 14:19:38 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	i;

	i = 0;
	while (i < (int) n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < (int) n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
