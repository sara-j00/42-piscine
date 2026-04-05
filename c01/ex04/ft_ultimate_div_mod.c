/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ultimate_div_mod.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 18:06:28 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/03 18:18:40 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

int main()
{
	int a=39, b=5;
	ft_ultimate_div_mod(&a, &b);
	char c=a+'0', d=b+'0';
	write(1, &c, 1);
	write(1, &d, 1);
	return 0;
}
