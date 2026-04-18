/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:18:23 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/18 21:07:23 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "dict_index.h"

int					is_valid_onearg(char *num);
int					input_read(char **num);
void				delete_struct_array(struct s_dict_index ***dict, int sz);
void				convert_num(char *num, struct s_dict_index **dict);
struct s_dict_index	**read_and_parse_dict(char *file_to_read);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// invalid number of args given = return (-1)
// print "Error\n"?
// invalid number passed as arg = return (-2)
// print "Error\n"
// error in dictionary parsing = return (-3)
// print "Dict Error\n"
// take input from command line = return (1)
// run indefinitely
int	take_input(int argc, char **argv, char **file_to_read, char **num)
{
	if (argc == 2)
	{
		if (!(ft_strlen(argv[1]) == 1 && argv[1][0] == '-'))
		{
			if (!is_valid_onearg(argv[1]))
				return (-2);
			*num = argv[1];
		}
		else
			return (input_read(num));
	}
	else if (argc == 3)
	{
		if (is_valid_onearg(argv[2]))
			*file_to_read = argv[1];
		else
			return (-2);
		*num = argv[2];
	}
	else
		return (-1);
	return (0);
}

void	settle_error(int ret)
{
	if (ret == -1 || ret == -2)
		write(1, "Error\n", 6);
	else if (ret == -3)
		write(1, "Dict Error\n", 12);
}

int	main(int argc, char **argv)
{
	int					ret;
	char				*num;
	char				*file_to_read;
	struct s_dict_index	**dict_indexes;

	file_to_read = "numbers.dict";
	ret = take_input(argc, argv, &file_to_read, &num);
	dict_indexes = read_and_parse_dict(file_to_read);
	if (ret < 0 || dict_indexes == NULL)
	{
		if (dict_indexes == NULL)
			ret = -3;
		settle_error(ret);
		return (0);
	}
	convert_num(num, dict_indexes);
	while (ret == 1)
	{
		if (take_input(argc, argv, &file_to_read, &num) < 0)
			break ;
		convert_num(num, dict_indexes);
	}
	delete_struct_array(&dict_indexes, 10000);
	return (0);
}
