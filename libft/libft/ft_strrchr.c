/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:52:56 by aakcan            #+#    #+#             */
/*   Updated: 2022/05/28 14:18:38 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*beg;

	beg = (char *)s;
	while (*s)
		++s;
	while (beg <= s)
	{
		if (*s == (char)c)
			return ((char *)s);
		--s;
	}
	return (0);
}
