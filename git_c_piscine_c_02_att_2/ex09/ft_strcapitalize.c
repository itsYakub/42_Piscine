/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:37:24 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/27 14:39:50 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_special(char c)
{
	if (c >= ' ' && c <= '/')
	{
		return (1);
	}
	else if (c >= ':' && c <= '@')
	{
		return (1);
	}
	else if (c >= '[' && c <= '`')
	{
		return (1);
	}
	else if (c >= '{' && c <= '~')
	{
		return (1);
	}
	return (0);
}

int	ft_capitalize_char(char *c, int offset)
{
	if (c[offset] >= 'a' && c[offset] <= 'z')
	{
		c[offset] -= 32;
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
			ft_capitalize_char(&str[i], 0);
		else
		{
			if (ft_is_special(str[i]))
			{
				if (ft_capitalize_char(&str[i], 1))
					i++;
			}
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
