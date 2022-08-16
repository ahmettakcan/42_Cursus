/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:29:47 by aakcan            #+#    #+#             */
/*   Updated: 2022/07/29 06:35:05 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	get_bit2(int pid, char *str)
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

void	s_pid(char c)
{
	int			s;
	char		*send;
	char		str[100];
	static int	i = 0;

	send = "🛫 🍯 ✨ I got the signal ✨ 🍯🥺";
	str[i] = c;
	i++;
	if (c == 0)
	{
		s = ft_atoi(str);
		get_bit2(s, send);
		i = 0;
	}
}

void	server_func(int sig)
{
	static int	c = 0;
	static int	i = 7;
	static int	is_pid = 0;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	if (i == 0)
	{
		if (is_pid > 0)
		{
			s_pid(c);
			if (c == 0)
				is_pid = -1;
		}
		if (is_pid == 0)
			write(1, &c, 1);
		if (c == 0)
			is_pid++;
		i = 7;
		c = 0;
	}
	else
		i--;
}

int	main(void)
{
	ft_printf("Server PID : %d\n", getpid());
	signal(SIGUSR1, server_func);
	signal(SIGUSR2, server_func);
	while (1)
		pause();
	return (0);
}
