/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:45:40 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/11 15:53:59 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// ensures all elements in the newly created 2d array are 0
void	zero_out(int **arr, int limit)
{
	int	rows;
	int	ctri;
	int	ctrj;

	rows = limit + 2;
	ctri = 0;
	ctrj = 0;
	while (ctri < rows)
	{
		while (ctrj < rows)
			arr[ctri][ctrj++] = 0;
		ctrj = 0;
		ctri++;
	}
}

// makes new array with the same values and returns a pointer to it
// returns a pointer to the new 2d array
int	**copy_array(int **arr, int limit)
{
	int	**newarr;
	int	rows;
	int	ctri;
	int	ctrj;

	rows = limit + 2;
	ctri = 0;
	newarr = malloc(rows * sizeof(int *));
	while (ctri < rows)
		newarr[ctri++] = malloc(rows * sizeof(int));
	ctri = 0;
	ctrj = 0;
	while (ctri < rows)
	{
		while (ctrj < rows)
		{
			newarr[ctri][ctrj] = arr[ctri][ctrj];
			ctrj++;
		}
		ctrj = 0;
		ctri++;
	}
	return (newarr);
}

// places input values into outer edges of array
void	fill_array(int **arr, int limit, int ctr, int *inp_array)
{
	int	ctri;
	int	ctrj;

	ctri = 0;
	ctrj = 1;
	while (ctr < limit * 2)
	{
		arr[ctri][ctrj++] = inp_array[ctr++];
		if (ctrj > limit)
		{
			ctrj = 1;
			ctri = limit + 1;
		}
	}
	ctri = 1;
	ctrj = 0;
	while (ctr < limit * 4)
	{
		arr[ctri++][ctrj] = inp_array[ctr++];
		if (ctri > limit)
		{
			ctrj = limit + 1;
			ctri = 1;
		}
	}
}

// creates 2d array to start with
// returns a pointer to the new array
int	**start_array(int **arr, int limit, int *inp_array)
{
	int	ctri;
	int	rows;

	ctri = 0;
	rows = limit + 2;
	arr = malloc(rows * sizeof(int *));
	while (ctri < rows)
	{
		arr[ctri] = malloc(rows * sizeof(int));
		ctri++;
	}
	zero_out(arr, limit);
	fill_array(arr, limit, 0, inp_array);
	return (arr);
}

// delete 2d array
void	delete_array(int **arr, int limit)
{
	int	ctri;
	int	rows;

	ctri = 0;
	rows = limit + 2;
	while (ctri < rows)
	{
		free(arr[ctri++]);
	}
	free(arr);
}
