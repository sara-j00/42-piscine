/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:24:07 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/08 14:32:20 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (!(s1[i] || s2[i] || s1[i] == s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
int main()
{
	char str1[30] = "welcome";
	char str2[54] = "welconeeee";
	printf("%d,  ", ft_strncmp(str1, str2, 3));
	printf("%d,  ", ft_strncmp(str1, str2, 5));
	printf("%d", ft_strncmp(str1, str2, 7));
}*/
