/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 12:47:27 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/04 12:48:59 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_putnbr(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	size -= 1;
	while (i <= size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		i++;
		size--;
	}
}
/*
int	main()
{
	int	size = 8;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int	*ptr = arr;
	ft_putnbr(ptr, 8);
	for (int i=0; i<size; i++){
		printf("%d", ptr[i]);
	}
	return 0;
}
*/
