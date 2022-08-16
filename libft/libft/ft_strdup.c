/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:03:46 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 19:29:13 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    const char *s1 = "Bilgisayar";
    char *s2 = ft_strdup(s1);
    printf("İlk karakter dizisi: %s\n", s1);
    printf("Benzer olarak oluşturulan karakter dizisi: %s", s2);
    return 0;
}*/
