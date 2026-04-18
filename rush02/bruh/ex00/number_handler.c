/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:04:42 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/18 20:50:15 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "dict_index.h"

int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		ft_strlen(char *str);
char	*make_zero_string(int diff);

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

void	ones(char *num, struct s_dict_index **dict, int end)
{
	char				*ones_key;
	struct s_dict_index	*value;

	if (num[0])
	{
		ones_key = (char [2]){num[0], '\0'};
		value = find_key(ones_key, dict);
		if (!value)
			return ;
		write(1, value->value, value->value_len);
	}
	end--;
	write(1, " ", 1);
}

void	tens(char *num, struct s_dict_index **dict, int end)
{
	char				*tens_key;
	struct s_dict_index	*value;

	if (num[0] != '0' && ft_strlen(num) != 1)
	{
		tens_key = (char [3]){num[0], num[1], '\0'};
		if (tens_key[0] == '1')
		{
			value = find_key(tens_key, dict);
			write(1, value->value, value->value_len);
			return ;
		}
		else
		{
			tens_key[1] = '0';
			value = find_key(tens_key, dict);
			write(1, value->value, value->value_len);
		}
		if (num[1] != '0')
			write(1, "-", 1);
	}
	if (num[1] != '0')
		ones((char [2]){num[1], '\0'}, dict, end);
	else
		write(1, " ", 1);
}

void	hundreds(char *num, struct s_dict_index **dict, int end)
{
	struct s_dict_index	*value;

	if (num[0] != '0')
	{
		ones((char [2]){num[0], '\0'}, dict, end);
		value = find_key("100", dict);
		if (!value)
			return ;
		write(1, value->value, value->value_len);
	}
	if (num[1] != '0')
	{
		write(1, " ", 1);
		tens((char [3]){num[1], num[2], '\0'}, dict, end);
	}
	else if (num[2] != '0')
	{
		write(1, " ", 1);
		ones((char [2]){num[2], '\0'}, dict, end);
	}
	else
		write(1, " ", 1);
}

int	call_digits(char *num, int len, int *ctr, struct s_dict_index **dict)
{
	int	diff;

	diff = len - *ctr;
	if (num[*ctr] == '0')
	{
		if (len == 1)
			ones("0", dict, 0);
		(*ctr)++;
		return (-1);
	}
	if (diff % 3 == 1)
	{
		ones(num + *ctr, dict, (diff - 1) / 3);
		(*ctr)++;
	}
	else if (diff % 3 == 2)
	{
		tens(num + *ctr, dict, (diff - 1) / 3);
		*ctr += 2;
	}
	else if (diff % 3 == 0)
	{
		hundreds(num + *ctr, dict, (diff - 1) / 3);
		*ctr += 3;
	}
	return (0);
}

void	convert_num(char *num, struct s_dict_index **dict)
{
	int					len;
	int					ctr;
	int					diff;
	char				*zero_count;
	struct s_dict_index	*value;

	while (*num == '0' && ft_strlen(num) > 1)
		num++;
	len = ft_strlen(num);
	ctr = 0;
	while (ctr < len)
	{
		diff = len - ctr;
		if (call_digits(num, len, &ctr, dict) == -1)
			continue ;
		if (ctr >= len || diff <= 3)
			break ;
		diff = (((diff - 1) / 3) * 3) + 1;
		zero_count = make_zero_string(diff);
		value = find_key(zero_count, dict);
		write(1, value->value, value->value_len);
		write(1, " ", 1);
		free(zero_count);
		zero_count = NULL;
	}
	write(1, "\n", 1);
}
