/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 12:29:59 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/18 21:17:41 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_index.h"

int	ft_strlen(char *str);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

int	is_valid_onearg(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

struct s_dict_index	*find_key(char *key, struct s_dict_index **dict)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		if (ft_strlen(key) == dict[i]->key_len)
			if (ft_strncmp(dict[i]->key, key, dict[i]->key_len) == 0)
				return (dict[i]);
		i++;
	}
	return (0);
}
