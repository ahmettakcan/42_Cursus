#include "ft_printf.h"

int	ft_convert(char type, va_list *list)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += prnt_char(va_arg(*list, int));
	else if (type == 's')
		len += prnt_str(va_arg(*list, char *));
	else if (type == 'p')
	{
		len += write(1, "0x", 2);
		len += prnt_hexa(va_arg(*list, long long int), 1);
	}
	else if (type == 'x')
		len += prnt_hexa(va_arg(*list, unsigned), 1);
	else if (type == 'X')
		len += prnt_hexa(va_arg(*list, unsigned), 2);
	else if (type == 'i' || type == 'd')
		len += prnt_int(va_arg(*list, int));
	else if (type == 'u')
		len += prnt_uint(va_arg(*list, unsigned int));
	else if (type == '%')
		len += prnt_char('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;
	int		i;

	va_start(list, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			len += write(1, &str[i], 1);
		else if (str[i] == '%')
			len += ft_convert(str[++i], &list);
		i++;
	}
	va_end(list);
	return (len);
}
