/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:37:40 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/16 12:53:14 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	check(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < 48 || *str > 57)
		{
			write(1, "Error\n", 7);
			exit(1);
		}
		str++;
	}
}

char	buf(char *str, int index, int i)
{
	static char	*buf;

	if (index == 0)
		buf = str;
	if (index == 1)
		return (buf[i]);
	return (0);
}

void	signal_handl(int sig)
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
		if (c != buf(NULL, 1, index++))
		{
			write(1, "msg incorrect\n", 15);
			exit(1);
		}
		if (c == '\0')
		{
			write(1, "msg correct\n", 13);
			exit(0);
		}
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pidserver;

	i = 0;
	if (argc == 3)
	{
		check(argv[1]);
		pidserver = ft_atoi(argv[1]);
		buf(argv[2], 0, 1);
	}
	if (argc != 3 || pidserver < 0)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	signal(SIGUSR1, signal_handl);
	signal(SIGUSR2, signal_handl);
	while (argv[2][i])
		dec_to_bin(argv[2][i++], pidserver);
	dec_to_bin('\0', pidserver);
	while (1)
		pause();
	return (0);
}
