/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:23:41 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/11 15:54:47 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		**start_array(int **arr, int limit, int *inp_array);
int		**copy_array(int **arr, int limit);
int		is_valid(int **arr, int limit);
void	delete_array(int **arr, int limit);
void	print_array(int **arr, int limit);

static int	g_found;

// get width of table
int	get_limit(char *str)
{
	int	ret;
	int	len;

	ret = 0;
	len = 0;
	while (*str)
	{
		len++;
		if (*str != ' ')
		{
			if (*str <= '9' && *str >= '0')
				ret++;
			else
				return (-1);
		}
		str++;
	}
	if (ret % 4)
		return (-1);
	return (ret / 4);
}

// convert input from string to array of ints
// returns a poiner to the array of ints
int	*get_arr(char *input, int limit)
{
	int	*arr;
	int	ctr;

	arr = malloc((limit * 4) * sizeof(int));
	ctr = 0;
	while (*input)
	{
		if (*input != ' ')
		{
			arr[ctr++] = *input - '0';
		}
		input++;
	}
	return (arr);
}

// test: should i continue trying this array or stop now?
// returns 1 if you should stop, 0 if not
int	should_stop(int **arr, int limit, int cur)
{
	if (g_found)
		return (1);
	if (cur == limit * limit)
	{
		if (is_valid(arr, limit))
		{
			g_found = 1;
			print_array(arr, limit);
		}
		delete_array(arr, limit);
		return (1);
	}
	if (!is_valid(arr, limit))
		return (1);
	return (0);
}

// recursively generate all arrays and test
void	gen_arrays(int **arr, int limit, int cur)
{
	int	ctri;
	int	ctrj;
	int	it;
	int	**newarr;

	if (should_stop(arr, limit, cur))
		return ;
	it = 1;
	ctri = cur / limit + 1;
	ctrj = cur % limit + 1;
	while (it <= limit)
	{
		newarr = copy_array(arr, limit);
		newarr[ctri][ctrj] = it;
		gen_arrays(newarr, limit, cur + 1);
		it++;
	}
}

// compile: cc -Wall -Wextra -Werror -o rush01 *.c
// test case: ./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
int	main(int argc, char **argv)
{
	int		limit;
	int		**arr;
	int		*inp_array;
	char	*input;

	if (argc != 2)
	{
		write(1, "Invalid Input\n", 14);
		return (0);
	}
	input = argv[1];
	limit = get_limit(input);
	if (limit < 4)
	{
		write(1, "Invalid Input\n", 14);
		return (0);
	}
	inp_array = get_arr(input, limit);
	arr = NULL;
	arr = start_array(arr, limit, inp_array);
	g_found = 0;
	gen_arrays(arr, limit, 0);
	if (g_found == 0)
		write(1, "No Valid Solution Found\n", 24);
	return (0);
}
