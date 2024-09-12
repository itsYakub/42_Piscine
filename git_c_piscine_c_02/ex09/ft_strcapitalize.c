/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:37:24 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/26 14:00:40 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_capitalize_char(char *c, int offset)
{
	if (c[offset] >= 'a' && c[offset] <= 'z')
	{
		c[offset] -= 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			ft_capitalize_char(&str[i], 0);
		}
		else
		{
			if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			{
				ft_capitalize_char(&str[i], 1);
				i++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		i++;
	}
	return (str);
}
