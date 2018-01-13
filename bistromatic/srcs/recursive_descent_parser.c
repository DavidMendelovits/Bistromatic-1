/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:20:20 by ttran             #+#    #+#             */
/*   Updated: 2018/01/12 12:40:48 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"
/* You'll have to free nbr in the add/sub/mult/div/mod operations */
/* Then possibly free everything in ParseSum before returning values. */
/* grabNbr grabs the "nbr" from the expression if it's there, otherwise it returns a 0 string. */
/* Goes past starting zeros and spaces. This function handles "negatives"as a minus and nothing = zero, 
 * so it's fine */
bignum	*grabNbr(char **expression)
{
	bignum *nbr;
	int count;
	static int counter;
	int neg;

	count = 0;
	neg = 1;
	while (**expression == '0' || **expression == ' ')
		(*expression)++;
	if (counter != 0)
	{
		if (**expression == '-' && if_operators(*(*expression - 1)) == 1 && 
		(*(*expression + 1) >= '0' && *(*expression + 1) <= '9'))
		{
			neg *= -1;
			(*expression)++;
		}
	}
	while ((*expression)[count] >= '0' && (*expression)[count] <= '9')
		count++;
	nbr = malloc(sizeof(bignum));
	setNbr(nbr, count, expression, neg);
	counter++;
	return (nbr);
}

/* Returns nbr or calls parseSum if it encounters a parentheses, which will have its own priority */
bignum	*parseAtom(char **expression)
{
	bignum *nbr;
	
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
	return (grabNbr(expression));
}

/* Handles multiplication/division/modulus before addition/subtraction. */
bignum	*parseProduct(char **expression)
{
	bignum *nbr1;
	bignum *nbr2;
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
			nbr1 = mult_bignum(&nbr1, &nbr2);
		else if (op == '/')
			nbr1 = div_bignum(&nbr1, &nbr2);
		else if (op == '%')
			nbr1 = mod_bignum(&nbr1, &nbr2);
	}
	return (nbr1);
}

/* Handles addition/subtraction */
bignum *parseSum(char **expression)
{
	bignum *nbr1;
	bignum *nbr2;
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
			nbr1 = add_bignum(&nbr1, &nbr2);
		if (op == '-')
			nbr1 = sub_bignum(&nbr1, &nbr2);
	}
	return (nbr1);
}

void	recursive_descent_parser(char *expression)
{
	bignum *result;
	
	result = parseSum(&expression);
	if (result->sign == -1)
		write(1, "-", 1);
	ft_putstr(result->nbr);
}
