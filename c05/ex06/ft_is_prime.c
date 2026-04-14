/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 13:19:19 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/14 14:14:53 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_is_prime(int nb)
{
	int	i;
	
	if (nb < 0 || nb == 0 || nb == 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0 && i != nb)
			return (0);
		i++;
	}
	return (1);
}
/*
int main ()
{
	printf("%d \n", ft_is_prime(13));
	printf("%d \n", ft_is_prime(12));
        printf("%d \n", ft_is_prime(-2));
        printf("%d \n", ft_is_prime(2));
        printf("%d \n", ft_is_prime(157));
	return 0;
}*/
