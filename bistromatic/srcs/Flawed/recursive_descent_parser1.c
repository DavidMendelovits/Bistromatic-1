/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:18:23 by ttran             #+#    #+#             */
/*   Updated: 2018/01/09 23:13:06 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

int	ft_matoi(char **str)
{
	int neg;
	int nbr;

	nbr = 0;
	neg = 1;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			neg *= -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		nbr = nbr * 10 + (**str - '0');
		(*str)++;
	}
	return (nbr * neg);
}

int parseSum(char **expression)
{
	int pro1;
	int pro2;

	while (**expression == ' ')
		(*expression)++;
	pro1 = parseProduct(expression);
	while (**expression == '+')
	{
		(*expression)++;
		pro2 = parseProduct(expression);
		pro1 = pro1 + pro2;
	}
	while (**expression == '-')
	{
		(*expression)++;
		pro2 = parseProduct(expression);
		pro1 = pro1 - pro2;
	}
	return (pro1);
}

int parseProduct(char **expression)
{
	int fac1;
	int fac2;

	while (**expression == ' ')
		(*expression)++;
	fac1 = parseFactor(expression);
	while (**expression == '*')
	{
		(*expression)++;
		fac2 = parseFactor(expression);
		fac1 = fac1 * fac2;
	}
	while (**expression == '/')
	{
		(*expression)++;
		fac2 = parseFactor(expression);
		fac1 = fac1 / fac2;
	}
	while (**expression == '%')
	{
		(*expression)++;
		fac2 = parseFactor(expression);
		fac1 = fac1 % fac2;
	}
	return (fac1);
}

int	parseFactor(char **expression)
{
	int nbr;
	int sum;

	while (**expression == ' ')
		(*expression)++;
	if ((**expression >= '0' && **expression <= '9') || **expression == '-' || **expression == '+')
	{
		nbr = ft_matoi(expression);
		return (nbr);
	}
	else if (**expression == '(')
	{
		(*expression)++;
		sum = parseSum(expression);
		if (**expression == ')')
			(*expression)++;
		return (sum);
	}
	ft_putstr("Error!\n");
	exit (0);
}

void	recursive_descent_parser(char *expression)
{
	int result;
	int negcounter;

	negcounter = 1;
	while (*expression == '+' || *expression == '-')
	{
		if (*expression == '-')
			negcounter *= -1;
		expression++;
	}
	result = parseSum(&expression);
	ft_putnbr(result * negcounter);
	write(1, "\n", 1);
}
