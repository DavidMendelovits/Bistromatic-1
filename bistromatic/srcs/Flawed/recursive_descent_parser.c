/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:33:26 by ttran             #+#    #+#             */
/*   Updated: 2018/01/11 19:05:33 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"
/* This one works, but I'll have to convert it to handle strings */

int	ft_matoi(char **expression)
{
	int nbr;

	nbr = 0;
	while (**expression >= '0' && **expression <= '9')
	{
		nbr = nbr * 10 + (**expression - '0');
		(*expression)++;
	}
	return (nbr);
}

int	parseAtom(char **expression)
{
	int nbr;

	while (**expression == ' ')
		(*expression)++;
	if (**expression == '(')
	{
		(*expression)++;
		nbr = parseSum(expression);
		if (**expression == ')')
			(*expression)++;
		return (nbr);
	}
	return (ft_matoi(expression));
}

int	parseProduct(char **expression)
{
	int nbr1;
	int nbr2;
	char op;

	nbr1 = parseAtom(expression);
	while (**expression)
	{
		while (**expression == ' ')
			(*expression)++;
		op = **expression;
		if (op != '*' && op != '/' && op != '%')
			return (nbr1);
		(*expression)++;
		nbr2 = parseAtom(expression);
		if (op == '*')
			nbr1 *= nbr2;
		else if (op == '/')
			nbr1 /= nbr2;
		else if (op == '%')
			nbr1 %= nbr2;
	}
	return (nbr1);
}

int	parseSum(char **expression)
{
	int nbr1;
	int nbr2;
	char op;

	nbr1 = parseProduct(expression);
	while (**expression)
	{
		while (**expression == ' ')
			(*expression)++;
		op = **expression;
		if (op != '+' && op != '-')
			return (nbr1);
		(*expression)++;
		nbr2 = parseProduct(expression);
		if (op == '+')
			nbr1 += nbr2;
		else if (op == '-')
			nbr1 -= nbr2;
	}
	return (nbr1);
}

void	recursive_descent_parser(char *expression)
{
	int result;
	
	result = parseSum(&expression);
	ft_putnbr(result);
}
