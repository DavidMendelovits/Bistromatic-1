/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_bignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:55:27 by ttran             #+#    #+#             */
/*   Updated: 2018/01/11 18:56:52 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bistromatics.h"

bignum	*zero_mod(bignum **nbr1, bignum **nbr2)
{
	if ((*nbr2)->sign == 0)
	{
		del_struct(nbr1);
		del_struct(nbr2);
		ft_putstr("NOW YOU'VE FUCKED UP\n");
		exit (0);
		//return (NULL);
	}
	else
	{
		del_struct(nbr2);
		return (*nbr1);
	}
}

void	mod_num(bignum *nbr1, bignum *nbr2)
{
	int i;

	i = nbr1->i;
	nbr1->i = 0;
	while (nbr1->i <= i)
	{
		if (div_nbrcompare(nbr1, nbr2) == 1)
			while (div_numsub(nbr1, nbr2) == 1)
				;
		nbr1->i++;
	}
	nbr1->nbr = remalloc(&nbr1->nbr);
	nbr1->i = ft_strlen(nbr1->nbr) - 1;
}

bignum  *mod_bignum(bignum **nbr1, bignum **nbr2)
{
	if ((*nbr1)->sign == 0 || (*nbr2)->sign == 0 || nbrcompare(*nbr1, *nbr2) == 0)
		return (zero_mod(nbr1, nbr2));
	mod_num(*nbr1, *nbr2);
	del_struct(nbr2);
	return (*nbr1);
}