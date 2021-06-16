/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:37:40 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/16 12:50:00 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	dec_to_bin(char c, int pidserver)
{
	int	r;

	r = 0;
	while (r < 8)
	{
		if (c & 128)
			kill(pidserver, SIGUSR1);
		else
			kill(pidserver, SIGUSR2);
		c = c << 1;
		usleep(100);
		r++;
	}
}

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

int	main(int argc, char **argv)
{
	int	i;
	int	pidserver;

	i = 0;
	if (argc == 3)
	{
		check(argv[1]);
		pidserver = ft_atoi(argv[1]);
	}
	if (argc != 3 || pidserver < 0)
	{
		write(1, "Error\n", 7);
		exit(1);
	}
	while (argv[2][i])
		dec_to_bin(argv[2][i++], pidserver);
	return (0);
}
