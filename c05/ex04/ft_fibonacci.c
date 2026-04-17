/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 11:34:08 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/13 11:46:08 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_fibonacci(int index)
{
	int	a;
	int	b;

	if (index == 0 || index < 0)
		return (-1);
	if (index == 1)
		return (1);
	a = ft_fibonacci(index - 1);
	b = ft_fibonacci(index - 2);
	return (a + b);
}
/*
int main()
{
	printf("%d", ft_fibonacci(6));
	return 0;
}*/
