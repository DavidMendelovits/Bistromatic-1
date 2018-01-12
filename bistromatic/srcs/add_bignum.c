/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:49:18 by ttran             #+#    #+#             */
/*   Updated: 2018/01/11 18:47:42 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

bignum	*zero_add(bignum **nbr1, bignum **nbr2)
{
	if ((*nbr1)->sign == 0)
	{
		del_struct(nbr1);
		return (*nbr2);
	}
	else
	{
		del_struct(nbr2);
		return (*nbr1);
	} 
}

void	add_num(bignum *nbr1, bignum *nbr2, bignum *resultstruct)
{
	char *result;
	int	carry;

	carry = 0;
	result = malloc(sizeof(char) * (nbr1->i + 3));
	result[nbr1->i + 2] = '\0';
	while (nbr1->i >= 0)
	{
		result[nbr1->i + 1] = ((nbr1->nbr[nbr1->i] % 48 + nbr2->nbr[nbr2->i] % 48 + carry) % 10) + '0';
		carry = ((nbr1->nbr[nbr1->i] % 48 + nbr2->nbr[nbr2->i] % 48 + carry) / 10);
		nbr1->i--;
		nbr2->i--;
	}
	result[0]  = carry + '0';
	resultstruct->nbr = remalloc(&result);
	resultstruct->i = ft_strlen(resultstruct->nbr) - 1;
}

/* i is index of final digit, +1 for number of digits, +1 for null, +1 for addition max */
bignum *add_bignum(bignum **nbr1, bignum **nbr2)
{
	bignum *resultstruct;
	
	if ((*nbr1)->sign == 0 || (*nbr2)->sign == 0)
		return (zero_add(nbr1, nbr2));
	if	((*nbr1)->i != (*nbr2)->i)
		zero_padif(*nbr1, *nbr2);
	resultstruct = malloc(sizeof(bignum));
	add_num(*nbr1, *nbr2, resultstruct);
	/* For now, just set to positive only. Handle normalizer after */
	resultstruct->sign = 1;
	del_struct(nbr1);
	del_struct(nbr2);
	return (resultstruct);
}
