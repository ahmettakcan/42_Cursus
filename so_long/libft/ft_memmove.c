/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:47:59 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 16:11:10 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dd;
	unsigned char	*ss;

	dd = (unsigned char *)dst;
	ss = (unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (dd > ss)
		while (len-- > 0)
			dd[len] = ss[len];
	else if (dd < ss)
		ft_memcpy(dst, src, len);
	return (dst);
}
