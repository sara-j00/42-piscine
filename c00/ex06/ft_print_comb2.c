/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 16:51:52 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/03 17:49:33 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			char	temp1;
			char	temp2;
			char	temp3;
			char	temp4;
			
			temp1 = a / 10 + '0';
			temp2 = b % 10 + '0';
			temp3 = a / 10 + '0';
			temp4 = b % 10 + '0';
			
			write(1, &temp1, 1);
			write(1, &temp2, 1);
			write(1, " ", 1);
			write(1, &temp3, 1);
			write(1, &temp4, 1);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
int main()
{
	ft_print_comb2();
	return 0;
}
