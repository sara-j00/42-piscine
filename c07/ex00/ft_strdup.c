/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 16:44:19 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/15 17:31:13 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strdup(char *str)
{
	char	*copy;
	int		len;
	
	len = 0;
	while (str[len])
		len++;
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

int main()
{
	char *a = "sadfw";
	char *b = ft_strdup(a);
	printf("%s", b);
	free(b);
	return 0;
}
