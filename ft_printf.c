/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalwafi <lalwafi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:29:20 by lalwafi           #+#    #+#             */
/*   Updated: 2024/03/06 22:49:55 by lalwafi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	whatisit(va_list arguments, char format)
{
	int	counter2;

	counter2 = 0;
	if (format == 'c')
		counter2 += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		counter2 += ft_putstr(va_arg(arguments, char *));
	else if (format == 'x' || format == 'X')
		counter2 += ft_puthex(va_arg(arguments, unsigned int), format);
	else if (format == 'p')
		counter2 += ft_putptr(va_arg(arguments, void *));
	else if (format == 'd' || format == 'i')
		counter2 += ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		counter2 += ft_putunsigned(va_arg(arguments, unsigned int));
	else if (format == '%')
		counter2 += ft_putchar('%');
	return (counter2);
}

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(arguments, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += whatisit(arguments, format[i + 1]);
			i++;
		}
		else
			counter += ft_putchar(format[i]);
		i++;
	}
	return (counter);
}

// int	main()
// {
// 	// char	*a = "hello";
// 	// char c = 'a';
// 	// char *b = &c;
// 	int		count;
// 	// unsigned int	X = 658927;
// 	// count = ft_printf("here are the thingies:\n%c\n%s\n%p\n%d\n%i\n%u\n%x\n%X\n%%\n", 'c',a, b, 67, 67, X, 67, 67);
// 	count = ft_printf("%u\n", -1);
// 	printf("ft_printf had %d characters\n", count);
// 	printf("--------------------------------------\n");
// 	count = ft_printf("%u\n", -1);
// 	printf("printf had %d characters\n", count);
// }
