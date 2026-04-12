/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 13:12:29 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/11 15:56:59 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_valid_row(int **arr, int idx, int limit);
int	check_valid_row_reverse(int **arr, int idx, int limit);
int	check_valid_column(int **arr, int idx, int limit);
int	check_valid_column_reverse(int **arr, int idx, int limit);

// checks that all elements of the array 
// are valid given contraints of the problem
// it calls functions from brute_checker.c to check all rows/columns
int	check_valid_all(int **arr, int limit)
{
	int	ctr;
	int	ret;

	ctr = 1;
	while (ctr <= limit)
	{
		ret = 0;
		ret += check_valid_row(arr, ctr, limit);
		ret += check_valid_column(arr, ctr, limit);
		ret += check_valid_row_reverse(arr, ctr, limit);
		ret += check_valid_column_reverse(arr, ctr, limit);
		ctr++;
		if (ret != 4)
			return (0);
	}
	return (1);
}
