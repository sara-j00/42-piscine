/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_uppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:36:36 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/11 20:10:58 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= 65 && str[i] <= 90))
			return (0);
		i++;
	}
	return (1);
}
/*
int main()
{
	char a[55] = "ABCBDBS";
	char b[34] = "ACVasiug";
	printf("%d, %d", ft_is_uppercase(a), ft_is_uppercase(b));
	return 0;
}*/
