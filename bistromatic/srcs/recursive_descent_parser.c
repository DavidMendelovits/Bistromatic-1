/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_descent_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:20:20 by ttran             #+#    #+#             */
/*   Updated: 2018/01/10 14:13:55 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"
/* You'll have to free nbr in the add/sub/mult/div/mod operations */
/* Then possibly free everything in ParseSum before returning values. */
/* grabNbr grabs the "nbr" from the expression if it's there, otherwise it returns a 0 string. */
/* Goes past starting zeros and spaces. This function handles "negatives"as a minus and nothing = zero, 
 * so it's fine */
char	*grabNbr(char **expression)
{
	char *nbr;
	int count;

	count = 0;
	while (**expression == '0' || **expression == ' ')
		(*expression)++;
	while ((*expression)[count] >= '0' && (*expression)[count] <= '9')
		count++;
	if (count == 0)
	{
		nbr = malloc(sizeof(char) * 2);
		nbr[1] = '\0';
		nbr[0] = '0';
		return (nbr);
	}
	nbr = malloc(sizeof(char) * (count + 1));
	nbr[count] = '\0';
	count = 0;
	while (**expression >= '0' && **expression <= '9')
	{
		nbr[count] = **expression;
		(*expression)++;
	}
	return (nbr);
}

/* Returns nbr or calls parseSum if it encounters a parentheses, which will have its own priority */
char	*parseAtom(char **expression)
{
	char *nbr;
	
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
char	*parseProduct(char **expression)
{
	char *nbr1;
	char *nbr2;
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
char	*parseSum(char **expression)
{
	char *nbr1;
	char *nbr2;
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
	char *result;
	
	result = parseSum(&expression);
	ft_putstr(result);
}
