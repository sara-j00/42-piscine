/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:23:41 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/10 17:47:52 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**start_array(int **arr, int limit, int *inp_array);
int		**copy_array(int **arr, int limit);
int		ft_sqrt(int np);
int		is_valid(int **arr, int limit);
void	delete_array(int **arr, int limit);
void	print_array(int **arr, int limit);

static int	g_found;

int	get_limit(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (*str != ' ')
			ret++;
		str++;
	}
	return (ft_sqrt(ret));
}

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

void	gen_arrays(int **arr, int limit, int cur)
{
	int	ctri;
	int	ctrj;
	int	it;
	int	**newarr;

	if (cur == limit * limit || g_found || !is_valid(arr, limit))
	{
		if (is_valid(arr, limit) && cur == limit * limit)
		{
			g_found = 1;
			print_array(arr, limit);
		}
		delete_array(arr, limit);
		return ;
	}
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

	argc++;
	input = argv[1];
	limit = get_limit(input);
	inp_array = get_arr(input, limit);
	arr = NULL;
	arr = start_array(arr, limit, inp_array);
	g_found = 0;
	gen_arrays(arr, limit, 0);
	return (0);
}
