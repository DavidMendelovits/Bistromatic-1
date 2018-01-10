/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscput.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:50:10 by ttran             #+#    #+#             */
/*   Updated: 2018/01/09 22:43:07 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{	
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = nbr % 2000000000;
		nbr *= -1;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + '0');	
}
