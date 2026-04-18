/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:59:49 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/17 18:28:24 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *dict, char *key);
int		is_space(char *str);
int		skip_spaces(char *str, int i);
int		ft_strlen(char *str);

int	validate_input(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9' )
			return (0);
		i++;
	}
	return (1);
}

char	*find_value(char *key, char *dict)
{
	char	*pos;
	int		i;
	int		j;

	pos = ft_strstr(dict, key);
	if (!pos)
	{
		write(1, "no match\n", 9);
		return (0);
		}
	i = 0;
	while (pos[i] != ':')
		i++;
	pos = &pos[i];
	i = skip_spaces(pos, i);
	pos = &pos[i];
	return (pos);
}

void	print_value(char *key, char *dict)
{
	char	*value;
	int		i;
	int		len;

	value = find_value(key, dict);
	if (!value)
		return;
	i = 0;
	len = 0;
	while (value[len] != '\n')
		len++;
	len--;
	while (len > 0 && is_space(&value[len]))
		len--;
	while (i <= len)
	{
		write(1, &value[i], 1);
		i++;
	}
}
