#include "ft_printf.h"

int	prnt_char(char str)
{
	write(1, &str, 1);
	return (1);
}

int	prnt_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	prnt_hexa(unsigned long int nb, int s)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += prnt_hexa(nb / 16, s);
		len += prnt_hexa(nb % 16, s);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += prnt_char(nb + 48);
		else
		{
			if (s == 1)
				len += prnt_char(nb + 87);
			else
				len += prnt_char(nb + 55);
		}
	}
	return (len);
}

int	prnt_int(int nb)
{
	int		len;
	long	nnb;

	len = 0;
	nnb = nb;
	if (nnb < 0)
	{
		nnb *= -1;
		len += write(1, "-", 1);
	}
	if (nnb > 9)
	{
		len += prnt_int(nnb / 10);
		len += prnt_int(nnb % 10);
	}
	else if (nnb < 10)
		len += prnt_char(nnb + 48);
	return (len);
}

int	prnt_uint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb > 9)
	{
		len += prnt_int(nb / 10);
		len += prnt_int(nb % 10);
	}
	else if (nb < 10)
		len += prnt_char(nb + 48);
	return (len);
}
