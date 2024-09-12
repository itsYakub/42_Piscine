/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:13:24 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/27 09:15:38 by joleksia         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	strlen_dest;
	int	i;

	strlen_dest = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0' && i < (int) nb)
	{
		dest[strlen_dest + i] = src[i];
		i++;
	}
	dest[strlen_dest + i] = '\0';
	return (dest);
}
