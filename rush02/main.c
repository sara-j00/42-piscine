/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:18:23 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/18 13:16:13 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "dict_index.h"

int	is_valid_onearg(char *num);

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
int	take_input(int argc, char **argv, char **file_to_read, char **dict_str)
{
	if (argc == 2)
	{
		if (!(ft_strlen(argv[1]) == 1 && argv[1][0] == '-'))
			if (!is_valid_onearg(argv[1]))
				return (-2);
	}
	else if (argc == 3)
	{
		if (is_valid_onearg(argv[2]))
			*file_to_read = argv[1];
		else
			return (-2);
	}
	else
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		ret;
	char	*num;
	char	*dict_str;
	char	*file_to_read;
	struct s_dict_index	*dict_indexes;

	file_to_read = "numbers.dict";
	ret = take_input(argc, argv, &file_to_read, &dict_str);
	if (ret < 0)
	{
		if (ret == -1 || ret == -2)
			write(1, "Error\n", 6);
		else if (ret == -3)
			write(1, "Dict Error\n", 12);
		return (0);
	}
	dict_indexes = read_and_parse_dict(file_to_read);
	if (dict == NULL)
	{
		write(1, "Dict Error\n", 12);
		return (0);
	}
	/*
	file = open(file_to_read, O_RDONLY);
	dict_str = malloc(5000);
	read(file, dict_str, 5000);
	printf("%s", dict_str);
	free(dict_str);
	*/
	return (0);
}
