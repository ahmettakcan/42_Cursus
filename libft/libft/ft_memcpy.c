/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:06:10 by aakcan            #+#    #+#             */
/*   Updated: 2022/05/25 11:52:02 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dd;
	unsigned const char	*ss;

	ss = src;
	dd = dst;
	if (!n || dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	while (n--)
		*dd++ = *ss++;
	return (dst);
}
