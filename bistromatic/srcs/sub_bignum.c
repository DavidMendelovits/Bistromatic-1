/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_bignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:55:01 by ttran             #+#    #+#             */
/*   Updated: 2018/01/12 00:12:47 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bistromatics.h"

bignum	*zero_sub(bignum **nbr1, bignum **nbr2)
{
	if ((*nbr1)->sign == 0)
	{
		del_struct(nbr1);
		(*nbr2)->sign *= -1;
		return (*nbr2);		
	}
	else
	{
		del_struct(nbr2);
		return (*nbr1);
	}
}

void	sub_num(bignum *nbr1, bignum *nbr2, bignum **resultstruct)
{
	char *result;
	int borrow;	

	*resultstruct = malloc(sizeof(bignum));
	borrow = 0;
	result = malloc(sizeof(char) * nbr1->i + 2);
	result[nbr1->i + 1] = '\0';
	while (nbr1->i >= 0)
	{
		if ((nbr1->nbr[nbr1->i] % 48 - nbr2->nbr[nbr2->i] % 48 + borrow) < 0)
		{
			result[nbr1->i] = (nbr1->nbr[nbr1->i] % 48 + 10 - nbr2->nbr[nbr2->i] % 48 + borrow) + '0'; 
			borrow = -1;	
		}
		else
		{
			result[nbr1->i] = (nbr1->nbr[nbr1->i] % 48 - nbr2->nbr[nbr2->i] % 48 + borrow) + '0';
			borrow = 0;	
		}
		nbr1->i--;
		nbr2->i--;
	} 
	(*resultstruct)->nbr = remalloc(&result);
	(*resultstruct)->i = ft_strlen((*resultstruct)->nbr) - 1;
}

bignum	*normalize_sub(bignum **nbr1, bignum **nbr2)
{
	if ((*nbr1)->sign == -1 && (*nbr2)->sign == -1)
	{
		(*nbr2)->sign = 1;
		return (add_bignum(nbr1, nbr2));
	}
	else if ((*nbr1)->sign == -1 && (*nbr2)->sign == 1)
	{
		(*nbr2)->sign = -1;
		return (add_bignum(nbr1, nbr2));
	}
	else
	{
		(*nbr2)->sign = 1;
		return (add_bignum(nbr1, nbr2));	
	}
}

bignum  *sub_bignum(bignum **nbr1, bignum **nbr2)
{
	bignum *resultstruct;

	resultstruct = 0;
	if ((*nbr1)->sign == 0 || (*nbr2)->sign == 0)
		return (zero_sub(nbr1, nbr2));	
	if ((*nbr1)->i != (*nbr2)->i)
		zero_padif(*nbr1, *nbr2);
	if ((*nbr1)->sign == 1 && (*nbr2)->sign == 1)
	{
			
		if (nbrcompare(*nbr1, *nbr2) == 1)
		{
			sub_num(*nbr1, *nbr2, &resultstruct);
			resultstruct->sign = 1;
		}
		else
		{
			sub_num(*nbr2, *nbr1, &resultstruct);
			resultstruct->sign = -1;			
		}
	}
	else
		return (normalize_sub(nbr1, nbr2));	
	del_struct(nbr1);
	del_struct(nbr2);
	return (resultstruct);
}
