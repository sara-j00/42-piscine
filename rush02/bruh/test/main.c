/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:18:23 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/16 18:36:59 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	convert_num(char *num, char *dict);

char	*ft_strcpy(char *dest, char *src)
{
	char	*it;

	it = dest;
	while (*src != '\0')
	{
		*it = *src;
		src++;
		it++;
	}
	*it = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	int		file;
	char	*num;
	char	*dict_str;
	char	*file_to_read;

	file_to_read = malloc(13);
	ft_strcpy(file_to_read, "numbers.dict");
	if (argc == 2)
		num = argv[1];
	else if (argc == 3)
	{
		num = argv[2];
		free(file_to_read);
		file_to_read = argv[1];
	}
	else
	{
		free(dict_str);
		write(1, "Error\n", 6);
		return (0) ;
	}
	file = open(file_to_read, O_RDONLY);
	if (file < 0)
		return 0;
	dict_str = malloc(1000);
	if (!dict_str)
		return (0);
	read(file, dict_str, 1000);
	convert_num(num, dict_str);
	return (0);
}
