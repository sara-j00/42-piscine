/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:47:37 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/10 17:35:06 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_duplicates_rows(int **arr, int limit)
{
	int	i;
	int	j;
	int	num_used[10];

	i = 1;
	while (i <= limit)
	{
		j = 1;
		while (j <= limit)
		{
			num_used[j] = 0;
			j++;
		}
		j = 1;
		while (j <= limit)
		{
			if (arr[i][j] != 0)
			{
				if (num_used[arr[i][j]] == 1)
					return (0);
				num_used[arr[i][j]] = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_duplicates_cols(int **arr, int limit)
{
	int	i;
	int	j;
	int	num_used[10];

	i = 1;
	while (i <= limit)
	{
		j = 1;
		while (j <= limit)
		{
			num_used[j] = 0;
			j++;
		}
		j = 1;
		while (j <= limit)
		{
			if (arr[j][i] != 0)
			{
				if (num_used[arr[j][i]] == 1)
					return (0);
				num_used[arr[j][i]] = 1;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_clues_top(int **arr, int limit)
{
	int	i;
	int	j;
	int	max;
	int	count;
	int	clue;

	i = 1;
	while (i <= limit)
	{
		max = 0;
		count = 0;

		clue = arr[0][i];

		j = 1;
		while (j <= limit)
		{
			if (arr[j][i] > max)
			{
				max = arr[j][i];
				count++;
			}
			j++;
		}

		if (count != clue)
			return (0);

		i++;
	}
	return (1);
}

int	check_clues_bottom(int **arr, int limit)
{
	int	i;
	int	j;
	int	max;
	int	count;
	int	clue;

	i = 1;
	while (i <= limit)
	{
		max = 0;
		count = 0;

		clue = arr[limit + 1][i];

		j = limit;
		while (j >= 1)
		{
			if (arr[j][i] > max)
			{
				max = arr[j][i];
				count++;
			}
			j--;
		}

		if (count != clue)
			return (0);

		i++;
	}
	return (1);
}

int	check_clues_left(int **arr, int limit)
{
	int	i;
	int	j;
	int	max;
	int	count;
	int	clue;

	i = 1;
	while (i <= limit)
	{
		max = 0;
		count = 0;

		clue = arr[i][0];

		j = 1;
		while (j <= limit)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				count++;
			}
			j++;
		}

		if (count != clue)
			return (0);

		i++;
	}
	return (1);
}

int	check_clues_right(int **arr, int limit)
{
	int	i;
	int	j;
	int	max;
	int	count;
	int	clue;

	i = 1;
	while (i <= limit)
	{
		max = 0;
		count = 0;

		clue = arr[i][limit + 1];

		j = limit;
		while (j >= 1)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				count++;
			}
			j--;
		}

		if (count != clue)
			return (0);

		i++;
	}
	return (1);
}

// use arr[row][column]
int	is_valid(int **arr, int limit)
{

	if (!check_duplicates_rows(arr, limit))
		return (0);
	if (!check_duplicates_cols(arr, limit))
		return (0);
	if (!check_clues_top(arr, limit))
		return (0);
	if (!check_clues_bottom(arr, limit))
		return (0);
	if (!check_clues_left(arr, limit))
		return (0);
	if (!check_clues_right(arr, limit))
		return (0);
	return (1);
}
