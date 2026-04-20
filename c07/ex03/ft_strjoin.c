/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:58:35 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/20 19:53:00 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	calc_len(int size, char **strs, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i++ < size)
		len += ft_strlen(strs[i - 1]);
	len += ft_strlen(sep) * (size - 1);
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	i = 0;
	if (size == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * ((calc_len(size, strs, sep)) + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	i = 0;
	while (i < (size - 1))
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		i++;
	}
	ft_strcat(str, strs[i]);
	return (str);
}
/*
int main(void)
{
    char *arr[] = {"afag", "agtag"};
    char *se = ", ";
    char *joined = ft_strjoin(2, arr, se);
    printf("%s\n", joined);
    free(joined);
}*/
