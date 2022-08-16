/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:29:47 by aakcan            #+#    #+#             */
/*   Updated: 2022/07/29 06:30:02 by aakcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	server_func(int sig)
{
	static int	c = 0;
	static int	i = 7;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	if (i == 0)
	{
		write(1, &c, 1);
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
