/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:46:06 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/06 19:59:58 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] += 32;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i + 1] += 32;
		}
	}
	return (str);
}
int main()
{
	char *a = "hello l a-g t+v";
	char *b[15] = ft_strcapitalize(a);
	printf("%s", b);
	return 0;
}
