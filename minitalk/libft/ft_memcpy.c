/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:22:56 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 16:11:55 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dd;
	unsigned char	*ss;

	ss = (unsigned char *)src;
	dd = (unsigned char *)dst;
	if (!n || dst == src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	while (n--)
		*dd++ = *ss++;
	return (dst);
}
