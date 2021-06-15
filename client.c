/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:37:40 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/12 17:13:23 by yhadari          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int	i;
	int	pidserver;

	argc = 0;
	i = 0;
	pidserver = ft_atoi(argv[1]);
	while (argv[2][i])
		dec_to_bin(argv[2][i++], pidserver);
	return (0);
}
