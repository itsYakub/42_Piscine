/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:44:20 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/05 13:44:21 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct t_filebuf
{
	char	*file_name;
	char	*file_content;
} t_filebuf;

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_atoi(char *str)
{
	int	result;
	int	is_negative;

	result = 0;
	is_negative = -1;
	while (*str < 32)
	        str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = 10 * result - (*str++ - '0');
	return (result * is_negative);
}

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

char	*ft_strdup(char *src)
{
	char	*result;
	int		i;

	result = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (*src != '\0')
		result[i++] = *(src++);
	result[i] = '\0';
	return (result);
}

t_filebuf	*ft_filebuf_init(int file_count)
{
	t_filebuf	*result;

	if (!file_count)
		return (NULL);
	result = (t_filebuf *) malloc(file_count * sizeof(t_filebuf));
	if (!result)
		return (NULL);
	return (result);
}

int	ft_filebuf_populate(t_filebuf *filebuf, const char *filepath)
{
	char	fbuf[16384];
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	for(int i = 0; i < 16384; i++)
		fbuf[i] = 0;
	read(fd, fbuf, 16384);
	close(fd);

	filebuf->file_name = ft_strdup((char *) filepath);
	filebuf->file_content = ft_strdup(fbuf);

	if (!filebuf->file_content || !filebuf->file_name)
		return (0);
	return (1);
}

int ft_filebuf_display_name(t_filebuf *filebuf)
{
	if (!filebuf || !filebuf->file_name)
		return (0);
	write(1, "==> ", 4);
	write(1, filebuf->file_name, ft_strlen(filebuf->file_name));
	write(1, " <==\n", 5);
	return (1);
}

int ft_filebuf_display_content(t_filebuf *filebuf, int limit)
{
	int	i;
	int	slen;

	i = 0;
	if (!filebuf || !filebuf->file_content)
		return (0);
	slen = ft_strlen(filebuf->file_content);
	if (limit != 0)
	{
		if(limit < slen)
			i = slen - limit;
		else
			i = 0;
		while(i < slen && filebuf->file_content[i] != '\0')
		{
			write(1, &filebuf->file_content[i], 1);
			i++;
		}
		write(1, "\n", 1);
		return (1);
	}
	write(1, filebuf->file_content, slen);
	return (1);
}

int ft_filebuf_unload(t_filebuf **filebufs, int count)
{
	int	i;

	if (!filebufs || !filebufs[0])
		return (0);
	i = -1;
	while (++i < count)
	{
		if (!filebufs[0][i].file_name)
			return (0);
		free(filebufs[0][i].file_name);
		if (!filebufs[0][i].file_content)
			return (0);
		free(filebufs[0][i].file_content);
	}
	free(filebufs[0]);
	return (1);
}

int ft_error(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	return (1);
}

int	main(int argc, const char *argv[])
{
	int	current_arg_index;
	int	file_count;
	t_filebuf	*filebuf;

	file_count = argc - 1;
	current_arg_index = 1;
	if(argc > 1)
	{
		filebuf = ft_filebuf_init(file_count);

		for(int i = 0; i < file_count; i++, current_arg_index++) {
			if(!ft_filebuf_populate(&filebuf[i], argv[current_arg_index]))
				return (ft_error());
		}
		for(int i = 0; i < file_count; i++) {
			if(file_count != 1) {
				if(!ft_filebuf_display_name(&filebuf[i]))
					return (ft_error());
			}
			if(!ft_filebuf_display_content(&filebuf[i], 50))
				return (ft_error());
		}

		if(!ft_filebuf_unload(&filebuf, file_count))
			return (ft_error());
	}

	return (0);
}
