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
	unsigned int	destlen;
	unsigned int	srclen;
	unsigned int	copyspace;
	unsigned int	i;

	destlen = 0;
	while (destlen < size && dest[destlen])
		destlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (size == 0)
		return (destlen + srclen);
	if (destlen >= size)
		return (destlen + srclen);
	copyspace = size - destlen - 1;
	i = 0;
	while (src[i] && copyspace > 0)
	{
		dest[destlen + i] = src[i++];
		copyspace--;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
