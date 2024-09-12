/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:24:46 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/23 09:31:48 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	strlen;

	strlen = 0;
	while (str[strlen] != '\0')
	{
		strlen++;
	}
	write (1, str, strlen);
}
