/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 17:29:41 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/18 20:36:18 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(unsigned long n)
{
	char	*hex_digits;
	int		count;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += convert_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
	count++;
	return (count);
}

int	print_address(void *ptr)
{
	unsigned long	addr;
	int				len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	addr = (unsigned long)ptr;
	write(1, "0x", 2);
	len = convert_hex(addr);
	return (len + 2);
}

int	print_hex_upper(unsigned int n)
{
	char	*hex_upper;
	int		count;

	hex_upper = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += print_hex_upper(n / 16);
	write(1, &hex_upper[n % 16], 1);
	count++;
	return (count);
}

int	print_hex_lower(unsigned int n)
{
	char	*hex_lower;
	int		count;

	hex_lower = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_hex_lower(n / 16);
	write(1, &hex_lower[n % 16], 1);
	count++;
	return (count);
}
