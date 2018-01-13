/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_bignum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:43:13 by ttran             #+#    #+#             */
/*   Updated: 2018/01/11 23:37:01 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

int		nbrcompare(bignum *nbr1, bignum *nbr2)
{
	int i;

	i = 0;	
	while ((nbr1->nbr)[i])
	{
		if ((nbr1->nbr)[i] > (nbr2->nbr)[i])
			return (1);
		else if ((nbr1->nbr)[i] < (nbr2->nbr)[i])
			return (0);
		else
			i++;	
	}
	return (1);
}

char	*remalloc(char **result)
{
	int i;
	int len;
	char *finale;
	int n;

	n = 0;
	i = 0;
	while ((*result)[i] == '0')
		i++;
	if (i == 0)
		return (*result);	
	if ((ft_strlen(*result) - i) == 0)
		finale = ft_strzero();
	else
	{
		len = ft_strlen(*result);
		finale = malloc(sizeof(char) * (len - i + 1));
		finale[len - i] = '\0';
		while ((*result)[i])
			finale[n++] = (*result)[i++];	
	}
	free(*result);
	return (finale);
}

void	zero_padif(bignum *nbr1, bignum *nbr2)
{
	if (nbr1->i > nbr2->i)
		zero_pad(nbr1, nbr2);
	else
		zero_pad(nbr2, nbr1);
}

/* i is the index of the final digit, i + 1 is the # of digits. +1 for null term */
void	zero_pad(bignum *nbr1, bignum *nbr2)
{
	int pad;
	int n;
	int x;
	char *paddedstr;

	n = 0;
	x = 0;
	pad = nbr1->i - nbr2->i; 
	paddedstr = malloc(sizeof(char) * (nbr1->i + 2));
	paddedstr[nbr1->i + 1] = '\0';
	while (n < pad)
		paddedstr[n++] = '0';
	while (nbr2->nbr[x]) 
		paddedstr[n++] = nbr2->nbr[x++];
	free(nbr2->nbr);
	nbr2->nbr = paddedstr;
	nbr2->i = ft_strlen(paddedstr) - 1; 	
}
