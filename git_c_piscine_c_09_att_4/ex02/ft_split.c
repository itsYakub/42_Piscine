/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:28:04 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/10 12:28:05 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Description:
	1. We get the count of the words in the str string, separated by charset.
	2. We use two values to move through the string:
		- word_start - the first char after the separator
		- word_end - the last character before the separator
	3. We move through the string from the start to the first valud char
		(valid == isn't in the charset)
	4. We assign the value of word_start to that char
	5. We start doing the point 3.
		but this time we start from the first valid char to the separator
		(and assign the value separator_char - 1)
	6. We allocate enough memory to copy the string from start to end AND
		also the null terminator
	7. We repeat the process until we get all the possible words
	8. We return the table of strings
*/

#include <stdlib.h>

int	ft_str_contains(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_word_count(char *str, char *charset)
{
	int	result;

	while (ft_str_contains(charset, *str) || !(*str))
	{
		if (!(*str))
			return (0);
		str++;
	}
	result = 1;
	while (*str)
	{
		if (ft_str_contains(charset, *str))
		{
			while (ft_str_contains(charset, *str) || !(*str))
			{
				if (!(*str))
					return (result);
				str++;
			}
			result++;
		}
		str++;
	}
	return (result);
}

int	ft_word(char **dest, char *str, char *charset)
{
	int	word_start;
	int	word_end;
	int	i;

	word_start = 0;
	while (str[word_start] && ft_str_contains(charset, str[word_start]))
		word_start++;
	word_end = word_start;
	while (str[word_end] && !ft_str_contains(charset, str[word_end]))
		word_end++;
	*dest = (char *) malloc((word_end - word_start + 1));
	i = 0;
	str += word_start;
	while (word_start < word_end)
	{
		(*dest)[i++] = *str;
		word_start++;
		str++;
	}
	(*dest)[word_end] = '\0';
	return (word_end);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	int		result_index;
	char	**result;

	word_count = ft_word_count(str, charset);
	result = (char **) malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result_index = -1;
	while (++result_index < word_count)
		str += ft_word(&result[result_index], str, charset);
	result[result_index] = NULL;
	return (result);
}

// #include <stdio.h>

// int main() {
// 	char text[] = "RG1bhdZZ3nj pYQoV8u6iXYpFrXr0m0 ";
// 	char charset[] = "L ";

// 	char **split = ft_split(text, charset);

// 	for(int i = 0; i < ft_word_count(text, charset); i++) {
// 		printf("%s\n", split[i]);
// 	}
// }
