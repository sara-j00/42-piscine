/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:04:42 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/18 14:58:44 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

s_dict  *find_key(char *key, s_dict ** dict)
{
        int     i;
        int     comp;

        i = 0;
        while (dict[i] != NULL)
        {
                if (strncmp(dict[i]->key, key, dict[i].keylen) == 0)
                       return (dict[i]);
                i++;
        }
        return (0);
}

/*      while (struct dict[i].key != '\0')
        {
                comp = strncmp(key, dict[i]->key, dict[i]->keylen);
                if (comp == 0)
                {
                        print_value(dict[i]->value);
                        return (1);
                }
                i++;
        }
        return (-3);
}*/


void    tens(char *num, char *s_dict)
{

        /*      dict    *key;

        if (strlen(num) == 1)
        {
                key =  find_key(num, s_dict);
                print_value(1, key, 
        }
        if (!key)
        {
                write(1, "Dict Error\n", 11);
                return;
        }*/

        char    ten[3];
        char    one[2];
        s_dict          *key;

        if (num[0] == '\0')
        {
                one[0] = num[0];
                one[1] = '\0';

                key = find_key(key, dict);
                if (!key)
                        return;
                write(1, key->value, key->value_len);
        }

        if (num [1] == '\0')
        {
                write(1, " ",1);
                tens[0] = num[1];
        }
}


/*
        c[0] = num[0];
        c[1] = '0';
        c[2] = '\0';
        print_value(c, dict);
        if (num[1] != '0')
        {
                c2[0] = num[1];
                c2[1] = '\0';
                write(1, " ", 1);
                print_value(c2, dict);
        }
}*/

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

void	convert_num(char *num, dict *dict)
{
	int	len;

	len = ft_strlen(num);
	if (len == 1 || len == 2)
		tens(num, dict);
	else if (len == 3)
		hundreds(num, dict);
	else
		big_numbers(num, ict);
}
