/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 14:13:49 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/19 14:57:36 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	temp;

	if (min >= max)
	{
		*range = '\0';
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
	{
		*range = '\0';
		return (-1);
	}
	i = 0;
	temp = min;
	while (temp < max)
		(*range)[i++] = temp++;
	return (max - min);
}
/*
int main()
{
	int *arr;
	int len;
	len = ft_ultimate_range(&arr, 1, 4);
	int i = 0;
	while (i < len)
	{
		printf("%d, ", arr[i]);
		i++;
	}
	printf("\n%d, ", len);
	free(arr);
}*/
