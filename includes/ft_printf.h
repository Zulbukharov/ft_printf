/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azulbukh <azulbukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:43:09 by azulbukh          #+#    #+#             */
/*   Updated: 2018/12/06 00:20:49 by azulbukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

int						g_counter;

typedef enum			e_min_plus
{
	plus = 43,
	minus = 45
}						t_min_plus;

typedef enum			e_type
{
	no = 0,
	d,
	i,
	c,
	s,
	p,
	f,
	o,
	u,
	x,
	X,
	P,
}						t_type;

typedef struct			s_flags
{
	int					s_step1;
	int					f_minus;
	int					f_plus;
	int					f_hash;
	int					f_zero;

	int					f_hash_len;

	int					s_step2;
	int					w_arg_len;
	int					w_len;
	int					w_step_len;

	int					s_step3;
	int					p_len;
	int					p_zero;

	int					s_step4;
	int					m_h;
	int					m_hh;
	int					m_l_int;
	int					m_ll;
	int					m_l_float;
	int					m_step_len;

	int					s_step5;
	int					step;
	t_type				mod;

	int					int_len;
	t_min_plus			min_plus;
	int					int_step;
	int					k;
	int					di_len;
}						t_flags;

typedef struct			s_main
{
	va_list				arg;
	int					len; // len of all bytes
	
	char				*string;
	char				sym;

	void				*p;

	long long			di;
	// signed char			hhdi;
	// short				hdi;
	// long				ldi;
	// long long			lldi;

	// unsigned char		hhoux;
	// unsigned short		houx;
	// unsigned long		loux;
	unsigned long long	lloux;

	float				f;
	double				lf;
	long double			llf;
}						t_main;

int						ft_printf(char *format, ...);

#endif
