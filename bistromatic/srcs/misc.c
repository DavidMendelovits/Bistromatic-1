/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:53:51 by ttran             #+#    #+#             */
/*   Updated: 2018/01/10 14:15:06 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	set_bignumstruct(bignum *nbr1, bignum *nbr2, char *num1, char *num2)
{
	if (num1[0] == '0')
		nbr1->sign = 0;
	else if (num1[0] == '-')
		nbr1->sign = -1;
	else
		nbr1->sign = 1;
	if (num2[0] == '0')
		nbr2->sign = 0;
	else if (num2[0] == '-')
		nbr2->sign = -1;
	else
		nbr2->sign = 1;
	nbr1->lastdigit = ft_strlen(num1);
	nbr2->lastdigit = ft_strlen(num2);
}

int	ft_atoi(char *str)
{
	int neg;
	int nbr;

	nbr = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * neg);
}
