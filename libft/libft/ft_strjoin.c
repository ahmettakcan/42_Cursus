/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:51:00 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 21:25:04 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1));
	if (newstr == NULL)
		return (NULL);
	while (*s1 || *s2)
	{
		if (*s1)
			newstr[i] = *s1++;
		else if (*s2)
			newstr[i] = *s2++;
		i++;
	}
	newstr[i] = 0;
	return (newstr);
}
/*
#include <stdio.h>
int main(void){
	char const *ss1 = "ahmet";
	char const *ss2 = "akcan";
	char *res;
	res = ft_strjoin(ss1,ss2);
	printf("%s", res);
	}*/
