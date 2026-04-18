/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:59:43 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/17 15:59:46 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	skip_spaces(char *str, int i)
{
	if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	is_space(char *str)
{
	if (*str == ' ' || (*str >= 9 && *str <= 13))
		return (1);
	return (0);
}

char	*ft_strstr(char *dict, char *key)
{
	char	*pos;
	int		i;
	int		j;

	pos = dict;
	i = 0;
	if (key[0] == 0)
		return (pos);
	while (dict[i])
	{
		j = 0;
		while (key[j] != '\0' && dict[i + j] == key[j])
		{
			if ((key[j + 1] == '\0')
				&& (is_space(&dict[i + j])
					|| dict[i + j] == ':'))
			{
				pos = &dict[i];
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (0);
}
