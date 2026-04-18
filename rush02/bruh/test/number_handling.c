/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 10:18:04 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/18 11:04:04 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_value(char *key, char *dict);
int		ft_strlen(char *str);

#include <unistd.h>

void	tens(char *num, char *dict)
{
	char	c[3];
	char	c2[2];

	if (num [0] == '1')
		print_value(num, dict);
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
}

void	hundreds(char *num, char *dict)
{
	if (num[0] == '1')
	{
	}
}

void	after_hundreds(char  *num, char *dict)
{

}

void	convert_num(char *num, char *dict)
{
	int	len;

	len = ft_strlen(num);
	if (len == 1)
		print_value(num, dict);
	else if (len == 2)
		tens(num, dict);
	else if (len == 3)
		hundreds(num, dict);
	else
		after_hundreds(num, dict);
}
