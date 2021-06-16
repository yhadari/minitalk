/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:37:28 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/12 17:15:17 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handl(int sig)
{
	static char	c = 0;
	static int	i = 0;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	argc = 0;
	argv[0] = 0;
	ft_putnbr_fd(getpid(), 0);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handl);
	signal(SIGUSR2, signal_handl);
	while (1)
		pause();
	return (0);
}
