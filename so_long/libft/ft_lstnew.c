/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:04:48 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/23 02:56:59 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*a;

	a = malloc(sizeof(t_list));
	if (!a)
		return (0);
	a -> content = content;
	a -> next = NULL;
	return (a);
}
/*
#include <stdio.h>
int main(void){
	char i[] = "5";
	t_list *a;
    a = ft_lstnew(i);
	printf("%s",a->content);
}*/
