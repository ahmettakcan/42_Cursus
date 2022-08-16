/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 23:26:55 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 18:50:54 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			i;

	if (s1 == s2 || n == 0)
		return ((char) NULL);
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int main(void){
	const char *cp1 = "Bilgisayar";
    const char *cp2 = "Bilgileri";
    int ret;

    ret = ft_memcmp(cp1, cp2, 10);

    if(ret<0) printf("cp1 bellek içeriği cp2 bellek içeriğinden küçüktür!");
    else if(ret>0) printf("cp2 bellek içeriği cp1 bellek içeriğinden küçüktür!");
    else printf("cp1 bellek içeriği cp2 bellek içeriğine eşittir!");

    return 0;
}*/
