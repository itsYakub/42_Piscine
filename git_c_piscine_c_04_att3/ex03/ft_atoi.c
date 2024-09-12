/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:48:59 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/30 11:59:51 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	while (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	is_negative;

	result = 0;
	is_negative = -1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = 10 * result - (*str++ - '0');
	}
	return (result * is_negative);
}

// #include <stdio.h>
// 
// int main() {
// 	printf("%i\n", ft_atoi("42"));
// 	printf("%i\n", ft_atoi("128"));
// 	printf("%i\n", ft_atoi("-64"));
// 	printf("%i\n", ft_atoi("-+-+1234"));
// 	printf("%i\n", ft_atoi("2147483647"));
// 	printf("%i\n", ft_atoi("-2147483648"));
// 	printf("%i\n", ft_atoi("4294967295"));
// 	printf("%i\n", ft_atoi("---+--+1234ab567"));
// }
