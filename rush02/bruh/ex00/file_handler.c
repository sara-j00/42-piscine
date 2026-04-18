/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:11:16 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/18 19:11:58 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "dict_index.h"

int		is_valid_onearg(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

char	*file_read(char *file_to_read)
{
	int		file;
	char	*ret;

	file = open(file_to_read, O_RDONLY);
	if (file == -1)
		return (NULL);
	ret = malloc(5000 * sizeof(char));
	if (ret != NULL)
		if (!read(file, ret, 5000))
			return (NULL);
	close(file);
	return (ret);
}

int	input_read(char **num)
{
	int				ret;
	unsigned int	ctr;
	char			current;
	char			buffer[5000];

	ctr = 0;
	ret = 0;
	while (read(0, &current, 1) > 0)
	{
		if (current == '\n')
		{
			ret = 1;
			break ;
		}
		buffer[ctr++] = current;
	}
	*num = malloc((ctr + 1) * sizeof(char));
	buffer[ctr] = 0;
	(*num)[ctr] = 0;
	ft_strncpy(*num, buffer, ctr + 1);
	if (is_valid_onearg(*num))
		return (ret);
	free(*num);
	if (ctr == 0)
		return (-5);
	return (-2);
}

void	delete_struct(struct s_dict_index *dict_index)
{
	free(dict_index->key);
	free(dict_index->value);
	free(dict_index);
}

void	delete_struct_array(struct s_dict_index ***dict_indexes, int sz)
{
	int	ctr;

	ctr = 0;
	while (ctr < sz && (*dict_indexes)[ctr] != NULL)
		delete_struct((*dict_indexes)[ctr++]);
	free(*dict_indexes);
}
