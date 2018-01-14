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

	if ((*nbr2)->sign == 0)
	{
		del_struct(nbr1);
		del_struct(nbr2);
		ft_putstr("NOW YOU'VE FUCKED UP\n");
		exit (0);
		//return (NULL);
	}
	else if ((*nbr1)->sign == 0)
	{
		del_struct(nbr2);
		return(*nbr1);
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

void	num_i2sub(bignum *nbr1, ss *s)
{
	nbr1->nbr[s->i1] = (nbr1->nbr[s->i1] % 48 + s->borrow) + '0';
	s->borrow = 0;
}

void	num_subber(bignum *nbr1, bignum *nbr2, ss *s)
{
	if ((nbr1->nbr[s->i1] % 48 - nbr2->nbr[s->i2] % 48 + s->borrow) < 0)
	{
		nbr1->nbr[s->i1] = (nbr1->nbr[s->i1] % 48 + 10 - nbr2->nbr[s->i2] % 48 + s->borrow) + '0'; 
		s->borrow = -1;	
	}
	else
	{
		nbr1->nbr[s->i1] = (nbr1->nbr[s->i1] % 48 - nbr2->nbr[s->i2] % 48 + s->borrow) + '0';
		s->borrow = 0;	
	} 
}

int	div_numsub(bignum *nbr1, bignum *nbr2)
{
	ss *s;

	s = malloc(sizeof(ss));
	s->i1 = nbr1->i;
	s->i2 = nbr2->i;
	s->borrow = 0;
	if (div_nbrcompare(nbr1, nbr2) == 1)
	{
		while (s->i2 >= 0)
		{
			num_subber(nbr1, nbr2, s);
			s->i1--;
			s->i2--;
		}
		if (s->i1 != -1)
			if (nbr1->nbr[s->i1] != '0')
				num_i2sub(nbr1, s);
	}
	else
	{
		free(s);
		return (0);
	}
	free(s);
	return (1);
}

/* Think about the remainder case as well as the zero case. */
void	div_num(bignum *nbr1, bignum *nbr2, bignum *resultstruct)
{
	char *result;
	int i;
	int numsubs;

	numsubs = 0;
	i = nbr1->i;
	result = malloc(sizeof(char) * (nbr1->i + 2));
	bcharzero(result, nbr1->i + 1);
	nbr1->i = 0;
	while (nbr1->i <= i)
	{
		if (div_nbrcompare(nbr1, nbr2) == 1)
		{
			while (div_numsub(nbr1, nbr2) == 1)
				numsubs++;
			result[nbr1->i] = numsubs + '0';
			numsubs = 0;
		}
		nbr1->i++;
	}
	resultstruct->nbr = remalloc(&result);
	resultstruct->i = ft_strlen(resultstruct->nbr) - 1;
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