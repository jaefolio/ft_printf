/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jifoo <jifoo@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 17:53:40 by jifoo             #+#    #+#             */
/*   Updated: 2026/08/18 18:28:58 by jifoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);

/*conversion helper functions*/
int	print_char(int c);
int	print_str(char *str);
int	print_decimal(int n);
int	print_unsigned(unsigned int n);
int	print_address(void *ptr);
int	print_hex_upper(unsigned int n);
int	print_hex_lower(unsigned int n);

#endif
