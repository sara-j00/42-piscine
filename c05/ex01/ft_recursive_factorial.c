/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 15:21:14 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/12 15:47:01 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_recursive_factorial(int nb)
{
	int	a;

	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	a = ft_recursive_factorial(nb - 1);
	return (nb * a);
}
/*
int main()
{
	printf("%d", ft_recursive_factorial(5));
	return 0;
}*/
