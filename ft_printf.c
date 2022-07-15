/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarslan <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:58:02 by rarslan           #+#    #+#             */
/*   Updated: 2022/05/07 17:27:35 by rarslan          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	isflag(char c)
{
	char	*flags;
	int		i;

	flags = "csdipuxX%";
	i = 0;
	while (flags[i])
	{
		if (flags[i++] == c)
			return (1);
	}
	return (0);
}

static int	putparam(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((char)(va_arg(args, int))));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_putptr(va_arg(args, void *)));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		rtn;

	rtn = 0;
	va_start(args, s);
	while (s && *s)
	{
		if (*s == '%' && isflag(*(s + 1)))
			rtn += putparam(*(s++ + 1), args);
		else
			rtn += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (rtn);
}
