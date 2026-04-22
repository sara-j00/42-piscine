/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:23:51 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/22 15:39:03 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_put_nbr(int nb)
{
	char	a;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_put_nbr(nb / 10);
	a = nb % 10 + '0';
	write(1, &a, 1);
}

void	ft_show_tab(struct s_stock_str *arr)
{
	int	i;

	i = 0;
	while (arr[i].copy)
	{
		write_str(arr[i].str);
		ft_put_nbr(arr[i].size);
		write(1, "\n", 1);
		write_str(arr[i].copy);
		i++;
	}
}
