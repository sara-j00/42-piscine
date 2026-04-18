/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:04:13 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/18 13:45:37 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "dict_index.h"

char	*file_read(char *file_to_read);
int	ft_strlen(char *str);

int	count_entries(char *dict_str)
{
	int	ret;

	if (dict_str == NULL)
		return (-1);
	ret = 0;
	while (*dict_str)
	{
		if(*dict_str == ':')
			ret++;
		dict_str++;
	}
	return (ret);
}

struct s_dict_index	*parse_line(char **dict_str)
{
	char	*key;
	char	*value;
	struct s_dict_index	*ret;

	key = get_key(dict_str);
	value = get_value(dict_str);
	if (key == NULL || value == NULL)
		return (NULL);
	ret = malloc(sizeof(struct s_dict_index));
	ret->key = key;
	ret->value = value;
	ret->key_len = ft_strlen(key);
	ret->value_len = ft_strlen(value);
	return (ret);
}

// this will return an array of indexes
// it represents the entire dictionary
struct s_dict_index	*read_and_parse_dict(char *file_to_read)
{
	int	entries;
	int	ctr;
	char	*dict_str;
	struct s_dict_index	**dict_indexes;

	dict_str = file_read(file_to_read);
	entries = count_entries(dict_str);
	dict_indexes = malloc((entries + 1) * sizeof(struct s_dict_index *));
	dict_indexes[entries] = NULL;
	if (dict_indexes == NULL || dict_str == NULL)
		return (NULL);
	ctr = 0;
	while (ctr < entries)
	{
		dict_indexes[ctr] = parse_line(&dict_str);
		if (dict_indexes[ctr] == NULL)
		{
			delete_struct_array(dict_indexes, ctr);
			return (NULL);
		}
		ctr++;
	}
	return (dict_indexes);
}
