/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:15:03 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/04 17:17:48 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(int c, char f, char m, char l)
{
	int	i;

	i = 1;
	while (i <= c)
	{
		if (i == 1)
			ft_putchar(f);
		else if (i == c)
			ft_putchar(l);
		else
			ft_putchar(m);
		i++;
	}
	ft_putchar(10);
}

void	rush(int col, char row)
{
	int	i;
	int	c;
	int	r;

	i = 1;
	c = col;
	r = row;
	while (c >=1 && r >=1)
	{
		while (i <= r)
		{
			if (i == 1)
				ft_print(c, '/', '*', 92);
			else if (i == r)
				ft_print(c, 92, '*', '/');
			else
				ft_print(c, '*', ' ', '*');
			i++;
		}
	}
}
