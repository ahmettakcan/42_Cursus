/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 20:47:00 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/22 21:39:30 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (s[r] != '\0' && s[r] != c)
		r++;
	return (r);
}

static size_t	word_count(char const *s, char c)
{
	size_t	r;

	r = 0;
	while (*s != '\0')
	{
		if (*s != c && (s[1] == '\0' || s[1] == c))
			r++;
		s++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	char		**r;
	size_t		i;
	size_t		l;
	size_t		word_idx;

	if (!s)
		return (NULL);
	l = word_count(s, c);
	r = (char **)malloc(sizeof(char *) * l + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		while (*s == c && *s != '\0')
			s++;
		r[i] = (char *)malloc(sizeof(char) * word_len(s, c) + 1);
		word_idx = 0;
		while (*s != c && *s != '\0')
			r[i][word_idx++] = *s++;
		r[i][word_idx] = '\0';
		i++;
	}
	r[i] = NULL;
	return (r);
}
/*
#include <stdio.h>
int main(void){
	char str[100] = "ali,cumali,veli";
	char **p = ft_split(str, ',');
	printf("%s\n%s\n%s\n", p[0],p[1],p[2]);
//word count kaca bolecegine bakar 2 , var diye 2 kere bolecek
//
}*/
