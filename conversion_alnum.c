/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_alnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 13:53:14 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/18 20:36:01 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	write(1, &ch, 1);
	return (1);
}

int	print_str(char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
	{
		write(1, &str[len], 1);
		len++;
	}
	return (len);
}

int	print_decimal(int n)
{
	char	*digits;
	long	nb;
	int		count;

	digits = "0123456789";
	count = 0;
	nb = n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
		count += print_decimal(nb / 10);
	write (1, &digits[nb % 10], 1);
	count++;
	return (count);
}

int	print_unsigned(unsigned int n)
{
	char	*digits;
	int		count;

	digits = "0123456789";
	count = 0;
	if (n >= 10)
		count += print_unsigned(n / 10);
	write (1, &digits[n % 10], 1);
	count++;
	return (count);
}
