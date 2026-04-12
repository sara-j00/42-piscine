/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:38:14 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/11 15:56:39 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function was only made to shorten other functions
// returns 1 if you can see the right amount of boxes from each input
// 0 if not
int	check_end(int count, int check, int is_complete)
{
	if (is_complete)
	{
		if (count != check)
			return (0);
	}
	else
		if (count > check)
			return (0);
	return (1);
}

int	check_valid_row(int **arr, int idx, int limit)
{
	int	ctrj;
	int	count;
	int	current_max;
	int	is_complete_row;

	is_complete_row = 1;
	current_max = 0;
	count = 0;
	ctrj = 1;
	while (ctrj <= limit)
	{
		if (arr[idx][ctrj] > current_max)
		{
			current_max = arr[idx][ctrj];
			count++;
		}
		if (arr[idx][ctrj] == 0)
			is_complete_row = 0;
		ctrj++;
	}
	return (check_end(count, arr[idx][0], is_complete_row));
}

int	check_valid_row_reverse(int **arr, int idx, int limit)
{
	int	ctrj;
	int	count;
	int	current_max;
	int	is_complete_row;

	is_complete_row = 1;
	current_max = 0;
	count = 0;
	ctrj = limit;
	while (ctrj >= 1)
	{
		if (arr[idx][ctrj] > current_max)
		{
			current_max = arr[idx][ctrj];
			count++;
		}
		if (arr[idx][ctrj] == 0)
			is_complete_row = 0;
		ctrj--;
	}
	return (check_end(count, arr[idx][limit + 1], is_complete_row));
}

int	check_valid_column(int **arr, int idx, int limit)
{
	int	ctri;
	int	count;
	int	current_max;
	int	is_complete_column;

	is_complete_column = 1;
	current_max = 0;
	count = 0;
	ctri = 1;
	while (ctri <= limit)
	{
		if (arr[ctri][idx] > current_max)
		{
			current_max = arr[ctri][idx];
			count++;
		}
		if (arr[ctri][idx] == 0)
			is_complete_column = 0;
		ctri++;
	}
	return (check_end(count, arr[0][idx], is_complete_column));
}

int	check_valid_column_reverse(int **arr, int idx, int limit)
{
	int	ctri;
	int	count;
	int	current_max;
	int	is_complete_column;

	is_complete_column = 1;
	current_max = 0;
	count = 0;
	ctri = limit;
	while (ctri >= 1)
	{
		if (arr[ctri][idx] > current_max)
		{
			current_max = arr[ctri][idx];
			count++;
		}
		if (arr[ctri][idx] == 0)
			is_complete_column = 0;
		ctri--;
	}
	return (check_end(count, arr[limit + 1][idx], is_complete_column));
}
