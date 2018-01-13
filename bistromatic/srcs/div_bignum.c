/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_bignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:55:21 by ttran             #+#    #+#             */
/*   Updated: 2018/01/11 18:56:26 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bistromatics.h"


bignum	*zero_div(bignum **nbr1, bignum **nbr2)
{
	bignum *resultstruct;

	if ((*nbr1)->sign == 0)
	{
		del_struct(nbr2);
		return(*nbr1);
	}
	else if ((*nbr2)->sign == 0)
	{
		del_struct(nbr1);
		del_struct(nbr2);
		ft_putstr("NOW YOU'VE FUCKED UP\n");
		exit (0);
		//return (NULL);
	}
	else
	{
		del_struct(nbr1);
		del_struct(nbr2);
		resultstruct = malloc(sizeof(bignum));
		resultstruct->nbr = ft_strzero();
		resultstruct->sign = 0;
		resultstruct->i = 0;
		return (resultstruct);
	}
}

void	div_num(bignum *nbr1, bignum *nbr2, bignum *resultstruct)
{
	
}

/* You'll need to have mod/div by 0 to return an error message. You can structure this in the future. */
bignum  *div_bignum(bignum **nbr1, bignum **nbr2)
{
	bignum *resultstruct;

	resultstruct = 0;
	if ((*nbr1)->sign == 0 || (*nbr2)->sign == 0 || nbrcompare(*nbr1, *nbr2) == 0)
		return (zero_div(nbr1, nbr2));
	resultstruct = malloc(sizeof(bignum));
	div_num(*nbr1, *nbr2, resultstruct);
	resultstruct->sign = (*nbr1)->sign * (*nbr2)->sign;
	del_struct(nbr1);
	del_struct(nbr2);
	return (resultstruct);
}