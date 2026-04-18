/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selnaji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:04:13 by selnaji           #+#    #+#             */
/*   Updated: 2026/04/18 21:20:30 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "dict_index.h"

char	*file_read(char *file_to_read);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	delete_struct_array(struct s_dict_index ***dict_indexes, int sz);
int		ft_strlen(char *str);
int		is_printable(char chr);
int		is_digit(char ch);

int	count_entries(char *dict_str)
{
	int	ret;

	if (dict_str == NULL)
		return (0);
	ret = 0;
	while (*dict_str)
	{
		if (*dict_str == ':')
			ret++;
		dict_str++;
	}
	return (ret);
}

char	*get_key(char **dict_str)
{
	unsigned int	ctr;
	char			*ret;

	ctr = 0;
	while ((*dict_str)[ctr] != ' ' && (*dict_str)[ctr] != ':')
	{
		if (is_digit((*dict_str)[ctr++]))
			return (NULL);
	}
	ret = malloc((ctr + 1) * sizeof(char));
	if (ctr == 0 || ret == NULL)
		return (NULL);
	ft_strncpy(ret, *dict_str, ctr);
	while (**dict_str >= '0' && **dict_str <= '9')
		(*dict_str)++;
	while (**dict_str != ':')
	{
		if (**dict_str != ' ')
		{
			free(ret);
			return (NULL);
		}
		(*dict_str)++;
	}
	return (ret);
}

char	*get_value(char **dict_str)
{
	char			*ret;
	unsigned int	ctr;

	if (**dict_str == ':')
		(*dict_str)++;
	while (**dict_str == ' ')
	{
		(*dict_str)++;
		if (!is_printable(**dict_str) || **dict_str == '\n')
			return (NULL);
	}
	ctr = 0;
	while ((*dict_str)[ctr] != '\n')
	{
		if (!is_printable(**dict_str))
			return (NULL);
		ctr++;
	}
	ret = malloc((ctr + 1) * sizeof(char));
	ft_strncpy(ret, *dict_str, ctr);
	while (**dict_str != '\n')
		(*dict_str)++;
	return (ret);
}

struct s_dict_index	*parse_line(char **dict_str)
{
	char				*key;
	char				*value;
	struct s_dict_index	*ret;

	while (**dict_str == '\n')
	{
		(*dict_str)++;
		if (**dict_str == 0)
			return (NULL);
	}
	key = get_key(dict_str);
	if (key == NULL)
		return (NULL);
	value = get_value(dict_str);
	if (value == NULL)
	{
		free(key);
		return (NULL);
	}
	ret = malloc(sizeof(struct s_dict_index));
	ret->key = key;
	ret->value = value;
	ret->key_len = ft_strlen(key);
	ret->value_len = ft_strlen(value);
	return (ret);
}

// this will return an array of indexes
// it represents the entire dictionary
struct s_dict_index	**read_and_parse_dict(char *file_to_read)
{
	int					entries;
	int					ctr;
	char				*dict_str;
	char				*dict_str_start;
	struct s_dict_index	**dict_indexes;

	dict_str = file_read(file_to_read);
	dict_str_start = dict_str;
	entries = count_entries(dict_str);
	dict_indexes = malloc((entries + 1) * sizeof(struct s_dict_index *));
	dict_indexes[entries] = NULL;
	if (dict_indexes == NULL || dict_str == NULL)
		return (NULL);
	ctr = 0;
	while (ctr < entries)
	{
		dict_indexes[ctr] = parse_line(&dict_str);
		if (dict_indexes[ctr++] == NULL)
		{
			free(dict_str_start);
			delete_struct_array(&dict_indexes, ctr - 1);
			return (NULL);
		}
	}
	free(dict_str_start);
	return (dict_indexes);
}
