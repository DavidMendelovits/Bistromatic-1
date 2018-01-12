/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:54:54 by ttran             #+#    #+#             */
/*   Updated: 2018/01/10 19:18:44 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

char	*addition(bignum *num_s1, bignum *num_s2, char *nbr1, char *nbr2)
{
	int resultsign;
	char *nbr;
	int nbrdigits;
	int carry;

	if (num_s1->i > num_s2->i)
	{
		nbr = malloc(sizeof(char) * (num_s1->i + 2));
		nbr[num_s1->i + 1] = '\0';
	}
	else
	{
		nbr = malloc(sizeof(char) * (num_s2->i + 2));
		nbr[num_s2->i + 1] = '\0';
	}
	while (num_s1->num_iter > 0 || num_s2->num_iter > 0)
	{
		if (num_s1->num_iter > 0 && num_s2->num_iter > 0) 
		{
				
			num_s1->num_iter--;
			num_s2->num_iter--;
		}
		else if (num_s1->num_iter > 0)
		{
			num_s1->num_iter--;
		}
		else if (num_s2->num_iter > 0)
		{
			num_s2->num_iter--;
		}
	}
}

char	*normalize_zero_a(bignum *num_s1, bignum *num_s2, char *nbr1, char *nbr2)
{
	char *nbr;

	if (num_s1->sign == '0' && num_s2->sign == '0')
	{
		nbr = malloc(sizeof(char) * 2);
		nbr[0] = '0';
		nbr[1] = '\0';
	}
	else if (num_s1->sign == '0')
		nbr = ft_strdup(nbr2);
	else if (num_s2->sign == '0')
		nbr = ft_strdup(nbr1);
	return (nbr);

}

char	*add_bignum(char **nbr1, char **nbr2)
{
	bignum *num_s1;
	bignum *num_s2;
	char *result;

	num_s1 = malloc(sizeof(bignum));
	num_s2 = malloc(sizeof(bignum));
	set_bignumstruct(num_s1, num_s2, *nbr1, *nbr2);
	if (num_s1->sign == 0 || num_s2->sign == 0)
		result = normalize_zero_a(num_s1, num_s2, *nbr1, *nbr2);
	else
		result = addition(num_s1, num_s2, *nbr1, *nbr2);
	free(*nbr1);
	free(*nbr2);
	free(num_s1);
	free(num_s2);
	return (result);
}
