/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saljawab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 18:19:29 by saljawab          #+#    #+#             */
/*   Updated: 2026/04/08 18:26:11 by saljawab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int len;

	len = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	len += i;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		len++;
		j++;
	}
	return (len);
}
