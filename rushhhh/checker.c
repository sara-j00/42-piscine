/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:47:37 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/11 15:55:39 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_valid_all(int **arr, int limit);

// use arr[row][column]
// ensures all elements in a newly created array are 0
void	zero_out_1d(int *arr, int size)
{
	int	ctr;

	ctr = 0;
	while (ctr < size)
		arr[ctr++] = 0;
}

int	is_unique_row(int **arr, int idx, int limit)
{
	int	ctrj;
	int	current;
	int	freq[10];

	zero_out_1d(freq, limit + 1);
	ctrj = 1;
	while (ctrj <= limit)
	{
		current = arr[idx][ctrj++];
		if (current == 0)
			break ;
		if (freq[current]++)
			return (0);
	}
	return (1);
}

int	is_unique_column(int **arr, int idx, int limit)
{
	int	ctri;
	int	current;
	int	freq[10];

	zero_out_1d(freq, limit + 1);
	ctri = 1;
	while (ctri <= limit)
	{
		current = arr[ctri++][idx];
		if (current == 0)
			break ;
		if (freq[current]++)
			return (0);
	}
	return (1);
}

// checks that all elements in rows/columns are unique
// this is another constraint in the project
// returns 1 if all elements are unique
int	is_unique(int **arr, int limit)
{
	int	ctr;

	ctr = 1;
	while (ctr <= limit)
	{
		if (!is_unique_row(arr, ctr, limit))
			return (0);
		if (!is_unique_column(arr, ctr, limit))
			return (0);
		ctr++;
	}
	return (1);
}

// return 1 if it is worth continuing with this array
// 0 if not
int	is_valid(int **arr, int limit)
{
	if (!is_unique(arr, limit))
		return (0);
	if (!check_valid_all(arr, limit))
		return (0);
	return (1);
}
