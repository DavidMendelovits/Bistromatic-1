/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:47:17 by ttran             #+#    #+#             */
/*   Updated: 2018/01/11 18:51:16 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

void	del_struct(bignum **nbr)
{
	(*nbr)->sign = 0;
	(*nbr)->i = 0;
	free((*nbr)->nbr);
	free(*nbr);
}

void	set_index_sign(bignum *nbrstruct)
{
	if (nbrstruct->nbr[0] == '0')
	{
		nbrstruct->sign = 0;
		nbrstruct->i = 0;	
	}
	else
	{
		nbrstruct->sign = 1;
		nbrstruct->i = (ft_strlen(nbrstruct->nbr) - 1); 
	}
}

void	setNbr(bignum *nbrstruct, int count, char **expression)
{
	if (count == 0)
	{
		nbrstruct->nbr = malloc(sizeof(char) * 2);
		nbrstruct->nbr[1] = '\0';
		nbrstruct->nbr[0] = '0';
	}
	else
	{
		nbrstruct->nbr = malloc(sizeof(char) * (count + 1));
		nbrstruct->nbr[count] = '\0';
		count = 0;
		while (**expression >= '0' && **expression <= '9')
		{
			nbrstruct->nbr[count] = **expression;
			count++;
			(*expression)++;
		}
	}
	set_index_sign(nbrstruct);
}
