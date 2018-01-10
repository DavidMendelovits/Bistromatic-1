/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bignum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 12:54:54 by ttran             #+#    #+#             */
/*   Updated: 2018/01/10 13:51:05 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"


char	*add_bignum(char **nbr1, char **nbr2)
{
	bignum *num_s1;
	bignum *num_s2;

	num_s1 = malloc(sizeof(bignum));
	num_s2 = malloc(sizeof(bignum));
	set_bignumstruct(num_s1, num_s2, nbr1, nbr2);
	if (num_s1->sign == 0 || num_s2->sign == 0)
		return (normalize_zero(num_s1, num_s2, nbr1, nbr2));
}
