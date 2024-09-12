/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:48:59 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/29 13:27:29 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (str[result])
	{
		result++;
	}
	return (result);
}

int	ft_atoi_trim_whitespaces(char **str)
{
	while (**str == ' '
		|| **str == '\t'
		|| **str == '\n'
		|| **str == '\v'
		|| **str == '\f'
		|| **str == '\r')
	{
		(*str)++;
	}
	return (0);
}

int	ft_atoi_get_minuses(char **str)
{
	int	result;

	result = 0;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			result++;
		(*str)++;
	}
	return (result);
}

int	ft_unit(int a)
{
	int	unit;
	int	pow;

	unit = 1;
	pow = -1;
	while (++pow < a)
	{
		unit *= 10;
	}
	return (unit);
}

int	ft_atoi(char *str)
{
	int	result;
	int	valid_char_count;
	int	minus_count;
	int	strlen_str;

	ft_atoi_trim_whitespaces(&str);
	minus_count = ft_atoi_get_minuses(&str);
	strlen_str = ft_strlen(str);
	result = 0;
	valid_char_count = 0;
	while (*str >= '0' && *str <= '9')
	{
		result += (*str - '0') * ft_unit(strlen_str - valid_char_count - 1);
		valid_char_count++;
		str++;
	}
	if (*str != '\0')
		result /= ft_unit(strlen_str - valid_char_count);
	if (minus_count % 2 == 1)
		result *= -1;
	return (result);
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
// 	printf("%i\n", ft_atoi(""));
// }