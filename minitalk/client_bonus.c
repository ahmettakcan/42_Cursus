/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:29:37 by aakcan            #+#    #+#             */
/*   Updated: 2022/07/29 06:36:38 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	get_bit(int pid, char *str)
{
	int	i;

	while (*str)
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
	i = 7;
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	server_func2(int sig)
{
	static int	c = 0;
	static int	i = 7;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	if (i == 0)
	{
		write(1, &c, 1);
		if (c == 0)
		{
			ft_printf("\n");
			exit(0);
		}
		i = 7;
		c = 0;
	}
	else
		i--;
}

int	main(int argc, char **argv)
{
	char	*ptr;

	ptr = ft_itoa(getpid());
	if (argc == 3 && argv[2][0] != 0)
	{
		signal(SIGUSR1, server_func2);
		signal(SIGUSR2, server_func2);
		get_bit(ft_atoi(argv[1]), argv[2]);
		get_bit(ft_atoi(argv[1]), ptr);
		free(ptr);
		while (1)
			pause();
	}
	return (0);
}
