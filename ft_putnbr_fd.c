/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhadari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:42:51 by yhadari           #+#    #+#             */
/*   Updated: 2021/06/12 17:18:01 by yhadari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static	void	checknum(int n, int *fd)
{
	if (n == -2147483648)
	{
		write(*fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(*fd, "0", 1);
		return ;
	}
	if (n == 2147483647)
	{
		write(*fd, "2147483647", 10);
		return ;
	}
}

static	int	lenum(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	void	revnum(int *n, int *ncopy, int *i)
{
	if (*n > 0)
		*ncopy = *n;
	*i = lenum(*n);
	if (*n < 0)
	{
		*ncopy = - *n;
		*i = lenum(- *n);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	j;
	int	ncopy;

	j = 9;
	if (n == 0 || n == -2147483648 || n == 2147483647)
	{
		checknum(n, &fd);
		return ;
	}
	revnum(&n, &ncopy, &i);
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (i-- > 0)
	{
		while (n > j)
			n = n / 10;
		j = (j * 10) + 9;
		ft_putchar_fd((n % 10) + 48, fd);
		n = ncopy;
	}
}
