/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bistromatics.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttran <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:04:12 by ttran             #+#    #+#             */
/*   Updated: 2018/01/12 00:35:03 by ttran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BISTROMATICS_H
# define BISTROMATICS_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_bignum
{
	int sign;
	int i;
	char *nbr;
}	bignum;

/* Main function */
int main(int argc, char **argv);

/* Writing functions */
void    ft_putstr(char *str);
void    ft_putchar(char c);
void    ft_putnbr(int nbr);

/* Remake of calculation parsing functions to handle string instead of ints */
bignum    *grabNbr(char **expression);
bignum    *parseAtom(char **expression);
bignum    *parseProduct(char **expression);
bignum    *parseSum(char **expression);
void    recursive_descent_parser(char *expression);

/* Validation of the string */


/* Integer handling. For sign, 1 is positive, 0 is zero, -1 is negative. 
 * In the struct, i stands for index of the final digit. */

/* Addition */
bignum	*add_bignum(bignum **nbr1, bignum **nbr2);
bignum  *zero_add(bignum **nbr1, bignum **nbr2);
void    add_num(bignum *nbr1, bignum *nbr2, bignum **resultstruct);
bignum  *normalize_add(bignum **nbr1, bignum **nbr2);

/* Subtraction */
bignum	*sub_bignum(bignum **nbr1, bignum **nbr2);
bignum  *zero_sub(bignum **nbr1, bignum **nbr2);
void    sub_num(bignum *nbr1, bignum *nbr2, bignum **resultstruct);
bignum  *normalize_sub(bignum **nbr1, bignum **nbr2);

/* Multiplication */
bignum	*mult_bignum(bignum **nbr1, bignum **nbr2);
bignum	*zero_mult(bignum **nbr1, bignum **nbr2);
void	mult_numadd(char *result, char *adder, int indexResult);
void	mult_digit(bignum *nbr1, bignum *nbr2, char *adder, int padder);
void	mult_num(bignum *nbr1, bignum *nbr2, bignum *resultstruct);

/* Division */
bignum	*div_bignum(bignum **nbr1, bignum **nbr2);


/* Modulus */
bignum	*mod_bignum(bignum **nbr1, bignum **nbr2);


/* Functions for bignum */
char    *remalloc(char **result);
void    zero_padif(bignum *nbr1, bignum *nbr2);
void    zero_pad(bignum *nbr1, bignum *nbr2);
int     nbrcompare(bignum *nbr1, bignum *nbr2);

/* Misc. functions */
int ft_atoi(char *str);
void    set_bignumstruct(bignum *nbr1, bignum *nbr2, char *num1, char *num2);
int ft_strlen(char *str);
char	*ft_strdup(char *str);
char    *ft_strnew(size_t size);
void	bcharzero(char *result, int nbr);
int		if_operators(char c);

/* Misc. functions for bignum */
void	zero_pad(bignum *nbr1, bignum *nbr2);
void	zero_padif(bignum *nbr1, bignum *nbr2);

/* Misc. functions for setting struct */
void	set_index_sign(bignum *nbrstruct, int neg);
void	setNbr(bignum *nbrstruct, int count, char **expression, int neg);
void	del_struct(bignum **nbr);
/* Base Handling */

#endif
