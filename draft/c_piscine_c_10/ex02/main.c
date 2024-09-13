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

#include "ft.h"
#include <fcntl.h>

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

int	ft_filebuf_len(char *filepath)
{
	char	c;
	int		res;
	int		fd;

	res = 0;
	fd = open(filepath, O_RDONLY);
	while (read(fd, &c, 1) > 0)
		res++;
	close(fd);
	return res;
}

int	ft_filebuf_populate(t_filebuf *filebuf, const char *filepath)
{
	char	*fbuf;
	int		flen;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	flen = ft_filebuf_len((char *) filepath);
	fbuf = (char *) malloc((flen + 1) * sizeof(char));
	read(fd, fbuf, flen);
	fbuf[flen] = 0;
	close(fd);

	filebuf->file_name = ft_strdup((char *) filepath);
	filebuf->file_content = ft_strdup(fbuf);

	if (!filebuf->file_content || !filebuf->file_name)
		return (0);
	free(fbuf);
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

int	ft_bytes_to_n_newline(char *str, int n)
{
	int	res;
	int	slen;

	res = 0;
	slen = ft_strlen(str);
	while(slen && n + 1)
	{
		if(str[slen] == '\n')
			n--;
		res++;
		slen--;
	}
	if(res == ft_strlen(str))
		return 0;
	return res - 2;
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
			if(!ft_filebuf_display_content(&filebuf[i],
				ft_bytes_to_n_newline(filebuf[i].file_content, 10)))
				return (ft_error());
			if(i < file_count - 1)
				write(1, "\n", 1);
		}

		if(!ft_filebuf_unload(&filebuf, file_count))
			return (ft_error());
	}

	return (0);
}
