/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:44:45 by aakcan            #+#    #+#             */
/*   Updated: 2022/05/25 11:50:30 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dd;
	unsigned const char	*ss;

	dd = dst;
	ss = src;
	if (len == 0 || dst == src)
		return (dst);
	if (dd > ss)
		while (len-- > 0)
			dd[len] = ss[len];
	else if (dd < ss)
		ft_memcpy(dst, src, len);
	return (dst);
}
