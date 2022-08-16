/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:29:37 by aakcan            #+#    #+#             */
/*   Updated: 2022/07/29 06:29:42 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_bit(int pid, char *str)
{
	int	i;

	while (*str != '\0')
	{
		i = 7;
		while (i >= 0)
		{
			if (*str >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		get_bit(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
