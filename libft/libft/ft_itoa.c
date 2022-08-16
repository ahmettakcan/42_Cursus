/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 00:29:37 by aakcan            #+#    #+#             */
/*   Updated: 2022/01/23 00:33:45 by aakcan           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int		len;
	int		nb;

	len = 0;
	nb = n;
	if (nb == 0)
	{
		len = 1;
		return (len);
	}
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int x)
{
	char		*s;
	size_t		len;
	int			n;

	n = x;
	if (x == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n) + 1;
	s = (char *)malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len - 1] = '\0';
	while (n)
	{
		s[--len - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%s", ft_itoa(234));
}
int to => string
int 32  long int 64 bit
*/
