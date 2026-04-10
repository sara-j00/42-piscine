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

//#include <stdio.h>

int	check(char str)
{
	if (str >= 32 && str <= 47)
		return (1);
	else if (str >= 58 && str <= 64)
		return (1);
	else if (str >= 91 && str <= 96)
		return (1);
	else if (str >= 123 && str <= 126)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		else if (check(str[i]))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[i + 1] -= 32;
			i++;
		}
		else
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
		i++;
	}
	return (str);
}
/*
int main()
{
	char a[] = "hello l a-g t+v";
	ft_strcapitalize(a);
	printf("%s", a);
	return 0;
}*/
