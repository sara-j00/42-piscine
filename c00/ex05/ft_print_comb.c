/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:09:18 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/02 16:10:19 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	arr[3];

	arr[0] = '0';
	while (arr[0] <= '7')
	{
		arr[1] = arr[0] + 1;
		while (arr[1] <= '8')
		{
			arr[2] = arr[1] + 1;
			while (arr[2] <= '9')
			{
				write(1, &arr[0], 1);
				write(1, &arr[1], 1);
				write(1, &arr[2], 1);
				write(1, " ", 1);
				arr[2]++;
			}
			arr[1]++;
		}
		arr[0]++;
	}
}

int main()
{
	ft_print_comb();
	return 0;
}
