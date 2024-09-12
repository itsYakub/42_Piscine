/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:26:49 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/29 15:29:06 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	strlen_dest;
	int	i;

	strlen_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < (int) size)
	{
		dest[strlen_dest + i] = src[i];
		i++;
	}
	dest[strlen_dest + i] = '\0';
	return (strlen_dest + i);
}
