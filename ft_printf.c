/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:51:37 by jifoo             #+#    #+#             */
/*   Updated: 2026/09/07 18:57:40 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_conversion(char c)
{
	char	*conversions;
	int		i;

	conversions = "cspdiuxX";
	i = 0;
	while (conversions[i])
	{
		if (c == conversions[i])
			return (1);
		i++;
	}
	return (0);
}

static int	conversion_checker(const char *s, va_list *args)
{
	int	i;

	i = 0;
	if (s[i] == 'c')
		return (print_char(va_arg(*args, int)));
	if (s[i] == 's')
		return (print_str(va_arg(*args, char *)));
	if (s[i] == 'p')
		return (print_address(va_arg(*args, void *)));
	if (s[i] == 'd' || s[i] == 'i')
		return (print_decimal(va_arg(*args, int)));
	if (s[i] == 'u')
		return (print_unsigned(va_arg(*args, unsigned int)));
	if (s[i] == 'x')
		return (print_hex_lower(va_arg(*args, unsigned int)));
	if (s[i] == 'X')
		return (print_hex_upper(va_arg(*args, unsigned int)));
	return (0);
}

static void	percent_checker(const char *s, va_list *args, int *i,
	int *output_counter)
{
	if (s[*i + 1] == '%')
	{
		write(1, "%", 1);
		(*i) += 2;
		(*output_counter)++;
	}
	else if (s[*i] && is_conversion(s[*i + 1]))
	{
		(*output_counter) += conversion_checker(&s[*i + 1], args);
		(*i) += 2;
	}
	else
	{
		(*output_counter) += print_char('%');
		(*i)++;
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		output_counter;

	va_start(args, s);
	i = 0;
	output_counter = 0;
	while (s[i])
	{
		if (s[i] == '%')
			percent_checker(s, &args, &i, &output_counter);
		else
		{
			write(1, &s[i], 1);
			i++;
			output_counter++;
		}
	}
	va_end(args);
	return (output_counter);
}
