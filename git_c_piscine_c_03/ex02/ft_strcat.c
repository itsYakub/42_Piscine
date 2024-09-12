/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:35:52 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/27 09:12:26 by joleksia         ###   ########.fr       */
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

char	*ft_strcat(char *dest, char *src)
{
	int	strlen_dest;
	int	i;

	strlen_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[strlen_dest + i] = src[i];
		i++;
	}
	dest[strlen_dest + i] = '\0';
	return (dest);
}
