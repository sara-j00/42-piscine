/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:04:42 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/18 15:58:41 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict_index.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n);
int	ft_strlen(char *str);

struct s_dict_index  *find_key(char *key, struct s_dict_index **dict)
{
        int     i;

        i = 0;
        while (dict[i])
        {
                if (ft_strncmp(dict[i]->key, key, dict[i]->key_len) == 0)
                       return (dict[i]);
                i++;
        }
        return (0);
}

void    tens(char *num, struct s_dict_index **dict)
{
        char    	tens_key[3];
        char    	ones_key[2];
        struct s_dict_index	*value;

        if (num[0] == '\0')
        {
                ones_key[0] = num[0];
                ones_key[1] = '\0';

                value = find_key(ones_key, dict);
                if (!value)
                        return;
                write(1, value->value, value->value_len);
		return;
        }

	tens_key[0] = num[0];
	tens_key[1] = num[1];
	tens_key[2] = '\0';
        
        value = find_key(tens_key, dict);
	if(!value)
		return;
	write(1, value->value, value->value_len);
	if (num[1] != '0')
	{
		write(1, " ", 1);
		ones_key[0] = num[1];
		ones_key[1] = '\0';
		value = find_key(ones_key, dict);
		if (!value)
			return;
		write(1, value->value, value->value_len);
	}
}

void    print_value(char *str)
{
        int     i;

        i = 0;
        while(str[i])
        {
                write(1, &str[i], 1);
                i++;
        }
}

void	convert_num(char *num, struct s_dict_index **dict)
{
	int	len;

	len = ft_strlen(num);
	if (len == 1 || len == 2)
		tens(num, dict);
	//else if (len == 3)
	//	hundreds(num, dict);
	//else
	//	big_numbers(num, ict);
}
