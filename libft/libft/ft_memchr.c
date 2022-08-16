/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:08:54 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 18:42:38 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*tmp_s;
	unsigned char		tmp_c;

	tmp_s = (unsigned const char *)s;
	tmp_c = (unsigned char)c;
	while (n--)
		if (*tmp_s++ == tmp_c)
			return ((void *)(tmp_s - 1));
	return (NULL);
}
/*
#include <stdio.h>
int main(void){
	char *a = "ahmet";
	char b = 'm';
	printf("%c karakterinin bellek adresi: %p\n", b, ft_memchr(a, b, ft_strlen(a)));
}*/
