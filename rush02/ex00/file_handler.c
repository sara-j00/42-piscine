/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:11:16 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/18 15:11:19 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "dict_index.h"

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
	while (ctr < sz)
		delete_struct((*dict_indexes)[ctr++]);
	free(*dict_indexes);
}
