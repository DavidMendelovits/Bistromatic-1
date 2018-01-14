/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:10:22 by ttran             #+#    #+#             */
/*   Updated: 2018/01/09 14:32:45 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bistromatics.h"

int main(int argc, char **argv)
{
	char	*buffer;
	//int		bytes_read;
/* Change argc back to 3 later */
	if (argc == 4)
	{
		//bytes_read = ft_atoi(argv[2]); 
		//buffer = malloc(sizeof(char) * (bytes_read + 1));
		//buffer[bytes_read] = '\0';
		buffer = ft_strdup(argv[3]);
		// read(0, buffer, bytes_read);
		recursive_descent_parser(buffer);		
	}
	else
		ft_putstr("Incorrect number of arguments, ./calc base input size\n");
	return (0);
}
