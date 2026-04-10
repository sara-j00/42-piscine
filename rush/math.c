/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:42:28 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/09 16:42:35 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	left;
	int	right;
	int	mid;

	left = 1;
	right = nb;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid > nb)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (0);
}
