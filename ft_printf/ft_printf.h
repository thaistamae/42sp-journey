/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttamae <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:38:25 by ttamae            #+#    #+#             */
/*   Updated: 2025/08/29 19:38:26 by ttamae           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		process_format(char a, va_list args);
char	*ft_utoa(unsigned int n);
char	*ft_utoa_hex(unsigned int n, int uppercase);
char	*ft_utoa_hex_ulong(unsigned long n, int uppercase);
int		handle_pointer(va_list args);
int		handle_char(va_list args);
int		handle_string(va_list args);
int		handle_int(va_list args);
int		handle_unsigned(va_list args);
int		handle_hex(va_list args, int uppercase);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
#endif
