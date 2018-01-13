/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:53:51 by ttran             #+#    #+#             */
/*   Updated: 2018/01/12 20:24:27 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

void	bcharzero(char *result, int nbr)
{
	int i;

	i = 0;
	while (i < nbr)
		result[i++] = '0';
	result[i] = '\0';
}

char	*ft_strnew(size_t size)
{
	char *str;
	size_t i;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	else
	{
		while (i <= size)
			str[i++] = 0;
	}
	return (str);
}

char	*ft_strdup(char *str)
{
	int i;
	char *s2;

	i = 0;
	while (str[i])
		i++;
	i++;
	s2 = malloc(sizeof(char) * i);
	if (!s2)
		return (NULL);
	i = 0;
	while (str[i])
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int neg;
	int nbr;

	nbr = 0;
	neg = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * neg);
}
