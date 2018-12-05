/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:42:04 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 00:59:32 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int d;//dec 4 byte
// int c;//char
// int s;//string
// int f;//flloat 4 bytes
// int F;//flloat 4 bytes upper
// int l;//long int
// int h;//short int
// int o;//octal
// int x;//hex lower
// int X;//hex upper

// при парсинге, если встретилась %, то создать структуру
// в которой будут присутствовать все флаги а также допилнительные
// #0-+
// void		ft_put_float(flat)

// int get_int_len_with_negative_too (int value){
//   int l=!value;
//   while(value){ l++; value/=10; }
//   return l;
// }
int			ft_get_int_len(long long value)
{
	int l;

	l = !value;
	while (value)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void	print_uns(unsigned long long int nb)
{
	if (nb == INTMAX_MAX)
		ft_putstr("9223372036854775807");
	if (nb >= 10 && nb != INTMAX_MAX)
	{
		print_uns(nb / 10);
		print_uns(nb % 10);
	}
	else if (nb != INTMAX_MAX)
	{
		ft_putchar(nb + '0');
	}
}

int			ft_get_uns_len(unsigned long long value)
{
	int l;

	l = 0;
	while (value)
	{
		l++;
		value /= 10;
	}
	return (l);
}

void	ft_upper_case(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}

void	zero_before_ples1(int len, t_flags *flags)
{
	int b;

	b = 0;
	if (flags->p_len > len && flags->w_len > flags->p_len)
	{
		b = flags->p_len - len;
		while (b > 0)
		{
			ft_putchar('0');
			b--;
		}
	}
}

void	zero_before_ples(char *str, t_flags *flags)
{
	int b;

	b = 0;
	if (flags->p_len > (int)ft_strlen(str) && flags->w_len > flags->p_len)
	{
		b = flags->p_len - ft_strlen(str);
		while (b > 0)
		{
			ft_putchar('0');
			b--;
		}
	}
}

void	print_struct(t_flags f)
{
	printf("[minus][%d]\n", f.f_minus);
	printf("[plus][%d]\n", f.f_plus);
	printf("[hash][%d]\n", f.f_hash);
	printf("[zero][%d]\n", f.f_zero);

	printf("[arg_len][%d]\n", f.w_arg_len);
	printf("[len][%d]\n", f.w_len);
	printf("[step_len][%d]\n", f.w_step_len);

	printf("[p_len][%d]\n", f.p_len);

	printf("[m_h][%d]\n", f.m_h);
	printf("[m_hh][%d]\n", f.m_hh);
	printf("[m_l_int][%d]\n", f.m_l_int);
	printf("[m_ll][%d]\n", f.m_ll);
	printf("[m_l_float][%d]\n", f.m_l_float);
	printf("[m_step_len][%d]\n", f.m_step_len);

	printf("[mod][%d]\n", f.mod);
}

// parse

int		check_for_flag(t_flags *flags, char c)
{
	if (c == '-' || c == '+' || c == '#' || c == '0')
	{
		flags->f_minus = c == '-' ? 1 : flags->f_minus;
		flags->f_plus = c == '+' ? 1 : flags->f_plus;
		flags->f_hash = c == '#' ? 1 : flags->f_hash;
		flags->f_zero = c == '0' ? 1 : flags->f_zero;
		flags->f_hash_len = flags->f_hash ? 2 : flags->f_hash_len;
		return (1);
	}
	else
		return (0);
}

int		check_for_width(char *format, t_flags *flags)
{
	// ft_putstr(&(*format));
	if (ft_atoi(&(*format)) > 0)
	{
		flags->w_len = ft_atoi(format);
		flags->w_step_len = ft_get_int_len((long long)flags->w_len);
		flags->s_step2 = 1;
		// ft_putnbr(flags->w_len);
		return (1);
	}
	return (0);
}

int		check_for_prec(t_flags *flags, char *format)
{
	if (!*format)
		return (0);
	flags->p_len = ft_atoi(format);
	if (!flags->p_len)
	{
		flags->p_zero = 1;
		return (0);
	}
	return (1);
}

int		check_for_type(t_flags *flags, char ch)
{
	if (ch == 'd' || ch == 'i' || ch == 'c' ||
	ch == 's' || ch == 'p' || ch == 'f' ||
	ch == 'o' || ch == 'u' || ch == 'x' ||
	ch == 'X' || ch == '%')
	{
		flags->mod = ch == 'd' ? d : flags->mod;
		flags->mod = ch == 'i' ? i : flags->mod;
		flags->mod = ch == 'c' ? c : flags->mod;
		flags->mod = ch == 's' ? s : flags->mod;
		flags->mod = ch == 'p' ? p : flags->mod;
		flags->mod = ch == 'f' ? f : flags->mod;
		flags->mod = ch == 'o' ? o : flags->mod;
		flags->mod = ch == 'u' ? u : flags->mod;
		flags->mod = ch == 'x' ? x : flags->mod;
		flags->mod = ch == 'X' ? X : flags->mod;
		flags->mod = ch == '%' ? P : flags->mod;
		return (1);
	}
	return (0);
}

int		check_for_mod(t_flags *flags, char *format)
{
	int d;

	d = 0;
	if ((d = ft_strncmp(format, "h", 1) == 0 ? 1 : d) > 0 ||
	(d  = ft_strncmp(format, "l", 1) == 0 ? 1 : d) > 0 ||
	(d = ft_strncmp(format, "L", 1) == 0 ? 1 : d) > 0 ||
	(d = ft_strncmp(format, "hh", 2) == 0 ? 2 : d) > 0 ||
	(d = ft_strncmp(format, "ll", 2) == 0 ? 2 : d) > 0)
	{
		flags->m_hh = ft_strncmp(format, "hh", 2) == 0 ? 1 : flags->m_hh;
		flags->m_h = ft_strncmp(format, "h", 1) == 0 ? 1 : flags->m_h;
		flags->m_l_int = ft_strncmp(format, "l", 1) == 0 ? 1 : flags->m_l_int;
		flags->m_ll = ft_strncmp(format, "ll", 2) == 0 ? 1 : flags->m_ll;
		flags->m_l_float = ft_strncmp(format, "L", 1) == 0 ? 1 : flags->m_l_float;
		flags->m_step_len = d;
		return (1);
	}
	return (0);
}

char	*set_flags(t_flags *flags, char *format)
{
	while (!format || *format != '\0')
	{
		if (check_for_flag(flags, *format) == 1)
			format++;
		else if (check_for_width(format, flags) > 0)
			format += flags->w_step_len;
		else if (*format == '.' && check_for_prec(flags, ++format) > 0)
			format += ft_get_int_len((uintmax_t)flags->p_len);
		else if (check_for_mod(flags, format))
			format += flags->m_step_len;
		else if (check_for_type(flags, *format) > 0)
			return (++format);
		else
			format++;
	}
	return (format);
}

// end of parse

void	print_whitespaces(t_flags *flags, int len)
{
	int z;

	if (flags->mod == f)
		z = flags->w_len - flags->p_len - len;
	else if (flags->mod == x || flags->mod == X ||
	flags->mod == o)
	{
		z = flags->w_len - len - flags->f_hash_len;
		if (flags->p_len < flags->w_len && flags->p_len > len)
			z = z - (flags->p_len - len);
	}
	else if (flags->mod == i || flags->mod == d)
	{
		z = flags->w_len - len - flags->int_len;
		if (flags->p_len < flags->w_len && flags->p_len > len)
			z = z - (flags->p_len - len);
	}
	else
		z = flags->w_len - len;
	if (flags->mod == d || flags->mod == i || flags->mod == u)
	{
		while (z > 0)
		{
			if (flags->f_zero && !flags->k)
				ft_putchar('0');
			else
				ft_putchar(' ');
			z--;
		}
	}
	else
	{
		while (z > 0)
		{
			if (flags->f_zero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			z--;
		}
	}
}

void	print_float(t_main *main, t_flags *flags)
{
	long double	f;
	int			d;
	int			arr[500];
	int			i;

	i = 0;
	f = main->llf - (int)main->llf;
	d = (int)main->llf;
	arr[i] = d;
	i++;
	while (f > 0 && i <= flags->p_len + 1)
	{
		f *= 10;
		arr[i] = (int)f;
		f -= (int)f;
		i++;
	}
	i--;
	if (i >= 0 && arr[i] >= 5 && i - 1 >= 0)
		arr[i - 1]++;
	i--;
	while (i >= 0)
	{
		if (arr[i] == 10 && i - 1 >= 0)
		{
			arr[i - 1]++;
			arr[i] = 0;
		}
		else
			break ;
		i--;
	}
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, ft_get_int_len(arr[0]) - 1);
	ft_putnbr(arr[0]);
	ft_putchar('.');
	for (int i = 1; i < flags->p_len + 1; i++)
		ft_putnbr(arr[i]);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, ft_get_int_len(arr[0]));
	
}

void	get_float(t_main *main, t_flags *flags)
{
	main->f = !flags->m_l_float && !flags->m_l_int ? va_arg(main->arg, double) : main->f;
	main->lf = flags->m_l_int ? va_arg(main->arg, double) : main->lf;
	main->llf = flags->m_l_float ? va_arg(main->arg, long double) : main->llf;

	main->llf = !flags->m_l_float && !flags->m_l_int ? main->f : main->llf;
	main->llf = flags->m_l_int ? main->lf : main->llf;
	print_float(main, flags);
}

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

void	print_address_hex(t_main *main, t_flags *flags)
{
	int			i;
	int			d;
	char		hex[16];
	uintptr_t	p;
	
	p = (uintptr_t)main->p;
	i = (sizeof(p) << 3) - 4;
	d = 0;
	if (flags->f_hash > 0)
		ft_putstr("0x");
	while (i >= 0)
	{
		hex[d] = hex_digit((p >> i) & 0xf);
		i -= 4;
		d++;
	}
	d = 0;
	while (d < 16 && hex[d] == '0')
		d++;
	ft_putstr(&hex[d]);
}

void	get_address(t_main *main, t_flags *flags)
{
	main->p = NULL;
	main->p = va_arg(main->arg, void*);
	print_address_hex(main, flags);
}

void	print_int(long long int nb)
{
	if (nb == INTMAX_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != INTMAX_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != INTMAX_MIN)
	{
		print_int(nb / 10);
		print_int(nb % 10);
	}
	else if (nb != INTMAX_MIN)
	{
		ft_putchar(nb + '0');
	}
}

void	print_int_w(t_main *main, t_flags *flags)
{
	flags->di_len = ft_get_int_len(main->di);
	if (main->di == 0 && flags->p_zero)
		flags->di_len = 0;
	if (flags->f_plus && main->di >= 0)
	{
		flags->int_len++;
		flags->min_plus = plus;
	}
	if (main->di < 0)
	{
		flags->min_plus = minus;
		flags->f_plus = 1;
		main->di *= -1;
		flags->int_len++;
	}
	flags->int_len = flags->p_len == flags->w_len ? 0 : flags->int_len;
	flags->k = flags->w_len > flags->p_len && flags->p_len > flags->di_len ? 1 : flags->k;
	if (flags->f_minus && flags->p_len > flags->di_len && flags->w_len > flags->p_len)
	{
		if (flags->f_plus && !flags->int_step && main->di >= 0)
		{
			ft_putchar(flags->min_plus);
			flags->int_step++;
		}
		if (flags->f_minus)
			zero_before_ples1(flags->di_len, flags);
	}
	if (flags->f_zero && flags->f_plus && !flags->int_step && main->di >= 0)
	{
		ft_putchar(flags->min_plus);
		flags->int_step++;
	}
	if (flags->w_len > 0 && !flags->f_minus)
	{
		print_whitespaces(flags, flags->di_len);
		if (flags->f_plus && !flags->int_step && main->di >= 0)
		{
			ft_putchar(flags->min_plus);
			flags->int_step++;
		}
	}
	if (!flags->f_minus)
	{
		zero_before_ples1(flags->di_len, flags);
	}
	if (!flags->f_zero && flags->f_plus && !flags->int_step && main->di >= 0)
		ft_putchar(flags->min_plus);
	if (flags->di_len > 0)
		print_int(main->di);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, flags->di_len);
}

void	get_int(t_main *main, t_flags *flags)
{
	main->di = va_arg(main->arg, long long);
	main->di = !flags->m_h && !flags->m_l_int ? (int)main->di : main->di;
	main->di = flags->m_hh ? (signed char)main->di : main->di;
	main->di = flags->m_h && !flags->m_hh ? (short)main->di : main->di;
	main->di = flags->m_l_int && !flags->m_ll ? (long)main->di : main->di;
	main->di = flags->m_l_int && flags->m_ll ? (long long)main->di : main->di;
	print_int_w(main, flags);
}

void	get_char(t_main *main, t_flags *flags)
{
	main->sym = 0;
	main->sym = va_arg(main->arg, int);
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, 1);
	ft_putchar(main->sym);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, 1);
}

void	print_string(t_main *main, t_flags *flags)
{
	if (main->string == NULL)
		main->string = ft_strdup("(null)");
	if (flags->p_len > 0)
		if (flags->p_len < (int)ft_strlen(main->string))
			main->string = ft_strsub(main->string, 0, flags->p_len);
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->string));
	ft_putstr(main->string);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, ft_strlen(main->string));
}

void	get_string(t_main *main, t_flags *flags)
{
	main->string = va_arg(main->arg, char*);
	print_string(main, flags);
}

void	print_hex(t_main *main, t_flags *flags)
{
	char *hex;

	hex = NULL;
	hex = ft_itoa_base_10_16(main->lloux);
	if (!*hex)
	{
		flags->f_hash_len = 0;
		if (flags->p_zero > 0)
		{
			if (flags->w_len > 0 && !flags->f_minus)
				print_whitespaces(flags, 0);
		}
		else
		{
			if (flags->w_len > 0 && !flags->f_minus)
				print_whitespaces(flags, 1);
			ft_putchar('0');
		}
	}
	else
	{
		if (flags->f_minus)
			zero_before_ples(hex, flags);
		if (flags->f_zero && flags->f_hash && flags->mod == x)
			ft_putstr("0x");
		if (flags->f_zero && flags->f_hash && flags->mod == X)
			ft_putstr("0X");
		if (flags->w_len > 0 && !flags->f_minus)
			print_whitespaces(flags, ft_strlen(hex));
		if (!flags->f_minus)
			zero_before_ples(hex, flags);
		if (flags->mod == X)
			ft_upper_case(hex);
		if (!flags->f_zero && flags->f_hash && flags->mod == x)
			ft_putstr("0x");
		if (!flags->f_zero && flags->f_hash && flags->mod == X)
			ft_putstr("0X");
		ft_putstr(hex);
	}
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, ft_strlen(hex));
}

void	print_octal(t_main *main, t_flags *flags)
{
	char *octal;

	octal = ft_itoa_base_10_8(main->lloux);
	if (ft_strlen(octal) == 0 && !flags->p_zero)
		ft_putchar('0');
	else
	{
		if (flags->f_minus && flags->p_len > (int)ft_strlen(octal) && flags->w_len > flags->p_len)
		{
			if (flags->f_minus)
				zero_before_ples(octal, flags);
		}
		if (flags->f_zero && flags->f_hash && flags->mod == o)
			ft_putstr("0");
		if (flags->w_len > 0 && !flags->f_minus)
			print_whitespaces(flags, ft_strlen(octal));
		if (!flags->f_minus)
			zero_before_ples(octal, flags);
		if (!flags->f_zero && flags->f_hash && flags->mod == o)
			ft_putstr("0");
		ft_putstr(octal);
		if (flags->w_len > 0 && flags->f_minus)
			print_whitespaces(flags, ft_strlen(octal));
	}
}

void	print_percent(t_flags *flags)
{
	if (flags->w_len > 0 && !flags->f_minus)
		print_whitespaces(flags, 1);
	ft_putchar('%');
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, 1);

}

void	print_unsigned(t_main *main, t_flags *flags)
{
	flags->di_len = ft_get_uns_len(main->lloux);
	flags->int_len = flags->p_len == flags->w_len ? 0 : flags->int_len;
	flags->k = flags->w_len > flags->p_len && flags->p_len > flags->di_len ? 1 : flags->k;
	if (flags->f_minus && flags->p_len > flags->di_len && flags->w_len > flags->p_len)
	{
		if (flags->f_minus)
			zero_before_ples1(flags->di_len, flags);
	}
	if (flags->w_len > 0 && !flags->f_minus)
	{
		print_whitespaces(flags, flags->di_len);
	}
	if (!flags->f_minus)
	{
		zero_before_ples1(flags->di_len, flags);
	}
	print_uns(main->lloux);
	if (flags->w_len > 0 && flags->f_minus)
		print_whitespaces(flags, flags->di_len);
}

void	get_hex_octal_unsigned(t_main *main, t_flags *flags)
{
	main->lloux = va_arg(main->arg, unsigned long long);
	main->lloux = !flags->m_h && !flags->m_l_int ? (unsigned int)main->lloux : main->lloux;
	main->lloux = flags->m_h && !flags->m_hh ? (unsigned short)main->lloux : main->lloux;
	main->lloux = flags->m_hh ? (unsigned char)main->lloux : main->lloux;
	main->lloux = flags->m_l_int && !flags->m_ll ? (unsigned long)main->lloux : main->lloux;
	main->lloux = flags->m_ll ? (unsigned long long)main->lloux : main->lloux;
	if (flags->mod == x || flags->mod == X)
		print_hex(main, flags);
	else if (flags->mod == o)
	{
		flags->f_hash_len = flags->f_hash ? 1 : 0;
		print_octal(main, flags);
	}
	else if (flags->mod == u)
		print_unsigned(main, flags);
}

void	get_arg(t_main *main, t_flags *flags)
{
	flags->f_zero = flags->f_minus ? 0 : flags->f_zero;
	if (flags->mod == d || flags->mod == x || flags->mod == X ||
		flags->mod == o || flags->mod == i || flags->mod == u)
	{
		// flags->k = flags->w_len > flags->p_len && flags->p_len > 
		flags->w_len = flags->p_len > flags->w_len ? flags->p_len : flags->w_len;
		flags->f_zero = flags->p_len == flags->w_len ? 1 : flags->f_zero;
		flags->f_minus = flags->f_zero && flags->w_len == flags->p_len ? 0 : flags->f_minus;
	}
	if (flags->mod == f)
	{
		flags->p_len = flags->p_len > 0 ? flags->p_len : 6;
		get_float(main, flags);
	}
	else if (flags->mod == p)
		get_address(main, flags);
	else if (flags->mod == d || flags->mod == i)
		get_int(main, flags);
	else if (flags->mod == x || flags->mod == X || flags->mod == o ||
		flags->mod == u)
		get_hex_octal_unsigned(main, flags);
	else if (flags->mod == c)
		get_char(main, flags);
	else if (flags->mod == s)
		get_string(main, flags);
	else if (flags->mod == P)
		print_percent(flags);
}

char	*check_for_pre(t_main *main, char *format)
{
	t_flags flags;

	format++;
	flags = (t_flags){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	format = set_flags(&flags, format);
	get_arg(main, &flags);
	// get_mod(main, flags)
	// print_struct(flags);
	return (format);
}

int		ft_printf(char *format, ...)
{
	t_main main;

	// num = 0;
	va_start(main.arg, format);
	while (*format != '\0')
	{
		// ft_putchar(' ');
		if (*format == '%')
			format = check_for_pre(&main, format);
		else
			ft_putchar(*format++);
	}
	va_end(main.arg);
	return (g_counter);
}

//%[флаги][ширина][точность][модификаторы][тип преобразования]
