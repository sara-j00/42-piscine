/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:31:04 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/22 15:10:38 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*copy;
	int		len;

	len = ft_strlen(str);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	len = 0;
	while (str[len])
	{
		copy[len] = str[len];
		len++;
	}
	copy[len] = '\0';
	return (copy);
}

void	ft_free(t_stock_str *s, int i)
{
	while (i >= 0)
	{
		free(s[i].copy);
		i--;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*s;
	int			i;

	s = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		if (!s[i].copy)
		{
			ft_free(s, i);
			return (NULL);
		}
		i++;
	}
	s[i].size = 0;
	s[i].copy = NULL;
	s[i].str = NULL;
	return (s);
}
/*
int main()
{
	char *arr[] = {"afag", "agtag"};
	int num = 2;
	t_stock_str *res = ft_strs_to_tab(num, arr);
	int i = 0;
	while(res[i].size > 0)
	{
		printf("%s\n", res[i].str);
		printf("%s\n", res[i].copy);
		printf("%d\n", res[i].size);
		i++;
	}
}*/
