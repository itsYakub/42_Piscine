/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:33:53 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/11 12:49:40 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* SECTION: Typedefs */

typedef struct s_map
{
	char			char_obst;
	char			char_empty;
	char			char_fill;
	char			**data;
	unsigned int	w;
	unsigned int	h;
}					t_map;

typedef struct s_bsq_data
{
	int				x;
	int				y;
	int				size;
}					t_bsq_data;

/* SECTION: Function declarations */

/* SECTION: Functions - file_parse.h */
int					ft_file_parse(int fd, char *fpath, char **str, int argc);
int					move_ptr(char *str, t_map *map);
int					ft_first_line(t_map *map, char *str);
int					ft_flen(char *filepath);

/* SECTION: Functions - map.c */
int					ft_create_map(t_map *map, char *file_str);
int					ft_print_map(t_map *map);
int					ft_unload_map(t_map *map);
int					ft_map_fill(t_map *map, t_bsq_data *bsq_data);

/* SECTION: Functions - find_bsq.c */
t_bsq_data			ft_find_bsq(t_map *map);

/* SECTION: Functions - utils.c */
int					ft_atoi(char *str);
void				ft_swap(int *a, int *b);
int					ft_strlen(char *s);
int					ft_logerr(char *err);
int					get_line_len(char *file_str, int i);

/* SECTION: Functions - map_validation.c */
int					validate_mape(char *file_str, t_map *map);

/* SECTION: Functions - scanf.c */
char	*ft_scanff(void);

#endif // BSQ_H
