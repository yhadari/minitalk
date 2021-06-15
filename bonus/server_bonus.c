/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:37:28 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/14 20:06:10 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send(char *server_buf, int signalpid)
{
	int	i;

	i = 0;
	while (server_buf[i])
		dec_to_bin(server_buf[i++], signalpid);
	dec_to_bin('\0', signalpid);
}

void	signal_handl(int sig, int signalpid, char *server_buf)
{
	static char	c = 0;
	static int	i = 0;
	static int	index = 0;

	c = c << 1;
	if (sig == SIGUSR1)
		c = c | 1;
	i++;
	if (i == 8)
	{
		server_buf[index++] = c;
		if (c == '\0')
		{
			server_buf[index] = '\0';
			index = 0;
			send(server_buf, signalpid);
		}
		else
			write(1, &c, 1);
		i = 0;
	}
}

void	get_pid(int sig, siginfo_t *info, void *context)
{
	int			signalpid;
	static char	*server_buf = NULL;

	if (!server_buf)
		server_buf = malloc(sizeof(char) * 10000);
	context = NULL;
	signalpid = info->si_pid;
	signal_handl(sig, signalpid, server_buf);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	argc = 0;
	argv[0] = 0;
	ft_putnbr_fd(getpid(), 0);
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_pid;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
