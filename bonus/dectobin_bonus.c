/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dectobin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <yhadari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:01:07 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/15 16:01:42 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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
