/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:13:27 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/04 10:13:28 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE 1
# define FALSE 0

# define EVEN(x) \
	(x % 2 == 0)

# define ODD(x) \
	(x % 2 == 1)

# define EVEN_MSG \
	"I have an even number of arguments."

# define ODD_MSG \
	"I have an odd number of arguments."

# define SUCCESS 0

typedef int	t_bool;

#endif
