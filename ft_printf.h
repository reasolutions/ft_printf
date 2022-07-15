/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:05:37 by rarslan           #+#    #+#             */
/*   Updated: 2022/05/11 20:38:02 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_printf(const char *s, ...);
int	ft_putptr(void *a);
int	ft_putnbr(int nbr);
int	ft_putstr(const char *s);
int	ft_putnbr_base(unsigned int n, char *base);

#endif
