/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:52:39 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/04 11:52:41 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// typedef struct s_stock_str
// {
// int size;
// char *str;
// char *copy;
// } t_stock_str;

int	ft_tablen(struct s_stock_str *par)
{
	int	result;

	result = 0;
	while (par[result].size != 0)
		result++;
	return (result);
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

void	ft_recursive_putnbr(unsigned int nb)
{
	char	c;

	if (nb / 10 > 0)
		ft_recursive_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nb_abs;

	nb_abs = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb_abs *= -1;
	}
	ft_recursive_putnbr(nb_abs);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	index;
	int	plen;

	plen = ft_tablen(par);
	index = -1;
	while (++index < plen)
	{
		write(1, par[index].str, ft_strlen(par[index].str));
		write(1, "\n", 1);
		ft_putnbr(par[index].size);
		write(1, "\n", 1);
		write(1, par[index].copy, ft_strlen(par[index].copy));
		write(1, "\n", 1);
	}
}
