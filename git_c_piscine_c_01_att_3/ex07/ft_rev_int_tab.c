/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:37:02 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/23 09:47:16 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = -1;
	temp = 0;
	while (++i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
	}
}

int main() {
	int tab[] = {
		10,
		9,
		8,
		7,
		6,
		5,
		4,
		3,
		2,
		1,
		0,
		22
	};

	ft_rev_int_tab(tab, sizeof(tab) / sizeof(int));
}
