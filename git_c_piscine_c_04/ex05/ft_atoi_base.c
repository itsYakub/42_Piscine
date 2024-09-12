/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:44:41 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/29 13:17:38 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BASE_TWO "01"
#define BASE_OCTAL "poneyvif"
#define BASE_DECIMAL "0123456789"
#define BASE_HEXADECIMAL "0123456789ABCDEF"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (result == 0)
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

int	ft_atoi(char *str, char *base)
{
	
}

int	ft_atoi_base(char *str, char *base)
{
	if(ft_strcmp(base, BASE_TWO) == 0)
		return (fr_atoi(str, BASE_TWO));
	else if(ft_strcmp(base, BASE_OCTAL) == 0)
		return (fr_atoi(str, BASE_OCTAL));
	else if(ft_strcmp(base, BASE_DECIMAL) == 0)
		return (fr_atoi(str, BASE_DECIMAL));
	else if(ft_strcmp(base, BASE_HEXADECIMAL) == 0)
		return (fr_atoi(str, BASE_HEXADECIMAL));
	return (0);
}
