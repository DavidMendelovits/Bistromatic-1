/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult_bignum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:55:11 by ttran             #+#    #+#             */
/*   Updated: 2018/01/12 13:52:16 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

bignum	*zero_mult(bignum **nbr1, bignum **nbr2)
{
	if ((*nbr1)->sign == 0)
	{
		del_struct(nbr2);
		return(*nbr1);
	}
	else
	{
		del_struct(nbr1);
		return (*nbr2);
	}
}
/* The max number of digits for multiplication is digits + digits. Meaning there won't be a carry over here at the end*/
void	mult_numadd(char *result, char *adder, int indexResult)
{
	int carry;
	int placeholder;

	carry = 0;
	placeholder = 0;
	while (indexResult >= 0)
	{
		placeholder = (result[indexResult] % 48 + adder[indexResult] % 48 + carry) % 10;
		carry = (result[indexResult] % 48 + adder[indexResult] % 48 + carry) / 10;
		result[indexResult] = placeholder + '0';
		indexResult--;
	}
}

/* This function uses the padder/index of the smaller number to perform single digit multiplication across all of the larger
 * number, with counter and iter being the incrementers. */
void	mult_digit(bignum *nbr1, bignum *nbr2, char *adder, int padder)
{
	int iter;
	int counter;
	int carry;

	carry = 0;
	counter = 0;
	iter = nbr1->i;
	while (iter >= 0)
	{
		adder[padder - counter] = (((nbr1->nbr[iter] % 48) * (nbr2->nbr[nbr2->i] % 48)) + carry) % 10 + '0';
		carry = (((nbr1->nbr[iter] % 48) * (nbr2->nbr[nbr2->i] % 48)) + carry) / 10;
		iter--;
		counter++;
	}
	adder[padder - counter] = carry + '0';
}

/* Padder is the size of the index of two numbers. That number +2 is the # of digits, - 1 is the index of the # of digits. 
 * Number of digits minus one is the index of the final digit. 
 * In this function, padder and the index of the smaller number are de-incremented. */
void	mult_num(bignum *nbr1, bignum *nbr2, bignum *resultstruct)
{
	char *result;
	char *adder;
	int carry;
	int padder;
	int indexResult;

	padder = nbr1->i + nbr2->i + 1;
	indexResult = padder;
	carry = 0;
	result = malloc(sizeof(char) * (padder + 2));
	bcharzero(result, padder + 1);
	while (nbr2->i >= 0)
	{
		adder = malloc(sizeof(char) * (nbr1->i + nbr2->i + 3));
		bcharzero(adder, nbr1->i + nbr2->i + 2);
		mult_digit(nbr1, nbr2, adder, padder);
		mult_numadd(result, adder, indexResult);
		free(adder);
		padder--;
		nbr2->i--;
	}
	resultstruct->nbr = remalloc(&result);
	resultstruct->i = ft_strlen(resultstruct->nbr) - 1;
}

bignum  *mult_bignum(bignum **nbr1, bignum **nbr2)
{
	bignum *resultstruct;

	resultstruct = 0;
	if ((*nbr1)->sign == 0 || (*nbr2)->sign == 0)
		return (zero_mult(nbr1, nbr2));
	resultstruct = malloc(sizeof(bignum));
	if (nbrcompare(*nbr1, *nbr2) == 1)
		mult_num(*nbr1, *nbr2, resultstruct);
	else
		mult_num(*nbr2, *nbr1, resultstruct);
	resultstruct->sign = (*nbr1)->sign * (*nbr2)->sign;  
	del_struct(nbr1);
	del_struct(nbr2);
	return (resultstruct);
}