/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:46:06 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/12 13:17:55 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
int	alphabet(char *str)
{
	if ((*str >= 'A' && *str <= 'Z')
		|| (*str >= 'a' && *str <= 'z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (alphabet(&str[i]))
		{
			if ((i == 0) || (!(alphabet(&str[i - 1]))
					&& (str[i] >= 'a' && str[i] <= 'z')))
				str[i] -= 32;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
/*
int main()
{
	char a[] = "hAVlo l a-g t+v";
	ft_strcapitalize(a);
	printf("%s", a);
	return 0;
}*/
