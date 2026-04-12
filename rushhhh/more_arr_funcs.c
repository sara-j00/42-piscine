/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_arr_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:25:45 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/10 17:26:42 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_array(int **arr, int limit)
{
	int		ctri;
	int		ctrj;
	char	out;

	ctri = 1;
	ctrj = 1;
	while (ctri <= limit)
	{
		while (ctrj <= limit)
		{
			out = arr[ctri][ctrj] + '0';
			write(1, &out, 1);
			ctrj++;
			if (ctrj > limit)
				break ;
			write(1, " ", 1);
		}
		ctri++;
		ctrj = 1;
		write(1, "\n", 1);
	}
}
