/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:34:46 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 21:24:40 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;

	if (!s1 || !set)
		return (0);
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	len = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[len]) && len > 0)
		len--;
	return (ft_substr((char *)s1, 0, len + 1));
}
/*
#include <stdio.h>
int main(void){
	char const *ss1 = "--ahmet--";
	char const *ss = "-";
	char *res;
	res = ft_strtrim(ss1, ss);
	printf("%s", res);
}*/
