/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:56:13 by chsassi           #+#    #+#             */
/*   Updated: 2023/11/18 18:56:14 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define BASE16 "0123456789abcdef"
# define BASE16UPPER "0123456789ABCDEF"
# define BASE10 "0123456789"

int		ft_printf(const char *str, ...);
void	ft_putaddr(void *ptr, int *length);
void	ft_putchar(char c, int *length);
void	ft_putnbr_base_unsigned_long(unsigned long nbr,
			char *base, int *length);
void	ft_putnbr_base_unsigned(unsigned int nbr, char *base, int *length);
void	ft_putnbr_base(long nbr, char *base, int *length);
void	ft_putstr(char *str, int *length);
int		xstrlen(char *str);
void	ft_specifiers(char c, va_list ap, int *length);

#endif
