/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:17:56 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/18 21:17:12 by selnaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_printable(char ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	return (0);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (!(s1[i] == s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*it;

	it = dest;
	while (*src != '\0')
	{
		*it = *src;
		src++;
		it++;
	}
	*it = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*it;

	it = dest;
	while (n && *src)
	{
		n--;
		*it = *src;
		src++;
		it++;
	}
	while (n--)
	{
		*it++ = '\0';
	}
	return (dest);
}

char	*make_zero_string(int diff)
{
	int		ctr;
	char	*ret;

	ret = malloc((diff + 1) * sizeof(char));
	ret[diff] = 0;
	ret[0] = '1';
	ctr = 1;
	while (ctr < diff)
		ret[ctr++] = '0';
	return (ret);
}
