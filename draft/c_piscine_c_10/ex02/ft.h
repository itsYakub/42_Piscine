/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:44:45 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/12 10:44:47 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

/* SECTION: includes */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/* SETION: typedefs */

typedef struct t_filebuf
{
	char	*file_name;
	char	*file_content;
} t_filebuf;

/* SECTION: utils.c */
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int 	ft_error(void);

#endif // FT_H
