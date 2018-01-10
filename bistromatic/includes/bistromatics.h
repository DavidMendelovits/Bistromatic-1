/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:04:12 by ttran             #+#    #+#             */
/*   Updated: 2018/01/10 13:14:54 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATICS_H
# define BISTROMATICS_H
# include <unistd.h>
# include <stdlib.h>

/* Main function */
int main(int argc, char **argv);

/* Writing functions */
void    ft_putstr(char *str);
void    ft_putchar(char c);
void    ft_putnbr(int nbr);

/* Misc. functions */
int ft_atoi(char *str);

/* Calculation parsing functions to ensure eval expression works 
void	recursive_descent_parser(char *expression);
int parseFactor(char **expression);
int parseProduct(char **expression);
int parseSum(char **expression);
int	ft_matoi(char **str); 
*/

/* Remake of calculation parsing functions to handle string instead of ints */
char    *grabNbr(char **expression);
char    *parseAtom(char **expression);
char    *parseProduct(char **expression);
char    *parseSum(char **expression);
void    recursive_descent_parser(char *expression);

/* Validation of the string */


/* Integer handling. For sign, 1 is positive, 0 is zero, -1 is negative. */
typedef struct s_bignum
{
	int sign;
	unsigned int lastdigit;
}				bignum;
char	*add_bignum(char **nbr1, char **nbr2);
char	*sub_bignum(char **nbr1, char **nbr2);
char	*mult_bignum(char **nbr1, char **nbr2);
char	*div_bignum(char **nbr1, char **nbr2);
char	*mod_bignum(char **nbr1, char **nbr2);

/* Base Handling */

#endif
