/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 15:53:19 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/27 16:28:26 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	type_s_num(char **ret, va_list args, int base)
{
	if (hash_check(g_type_table, 'l'))
		*ret = ft_itoa_base(va_arg(args, long long), base);
	else if (hash_check(g_type_table, 'z'))
		*ret = ft_itoa_base(va_arg(args, ssize_t), base);
	else if (hash_check(g_type_table, 'j'))
		*ret = ft_itoa_base(va_arg(args, intmax_t), base);
	else if (hash_check(g_type_table, 'h'))
		*ret = ft_itoa_base((char)va_arg(args, int), base);
	else if (hash_check(g_flag_table, 'l'))
		*ret = ft_itoa_base(va_arg(args, long), base);
	else if (hash_check(g_flag_table, 'h'))
		*ret = ft_itoa_base((short int)va_arg(args, int), base);
	else
		*ret = ft_itoa_base(va_arg(args, int), base);
	hash_check(g_conv_table, 'X') ? ft_strtoupper(ret) : 0;
}

void	type_u_num(char **ret, va_list args, int base)
{
	if (hash_check(g_type_table, 'l'))
		*ret = ft_itoa_base(va_arg(args, unsigned long long), base);
	else if (hash_check(g_type_table, 'z'))
		*ret = ft_itoa_base(va_arg(args, ssize_t), base);
	else if (hash_check(g_type_table, 'j'))
		*ret = ft_itoa_base(va_arg(args, uintmax_t), base);
	else if (hash_check(g_flag_table, 'l'))
		*ret = ft_itoa_base(va_arg(args, unsigned long), base);
	else
		*ret = ft_itoa_base(va_arg(args, unsigned int), base);
	hash_check(g_conv_table, 'X') ? ft_strtoupper(ret) : 0;
}

int		get_arg(char **ret, va_list args)
{
	if (g_message)
		*ret = ft_chartostr(g_message, 1);
	else if (hash_check(g_conv_table, 'i') || hash_check(g_conv_table, 'd'))
		type_s_num(ret, args, 10);
	else if (hash_check(g_conv_table, 's'))
		*ret = ft_strdup(va_arg(args, char *));
	else if (hash_check(g_conv_table, 'c'))
		*ret = ft_chartostr(va_arg(args, int), 1);
	else if (hash_check(g_conv_table, 'x') || hash_check(g_conv_table, 'X'))
		type_u_num(ret, args, 16);
	else if (hash_check(g_conv_table, 'o'))
		type_u_num(ret, args, 8);
	else if (hash_check(g_conv_table, 'p'))
		*ret = ft_itoa_base((long long)va_arg(args, void *), 16);
	else if (hash_check(g_conv_table, 'u'))
		type_u_num(ret, args, 10);
	else if (hash_check(g_conv_table, 'f'))
		*ret = ft_ftoa(va_arg(args, double), g_precision);
	else
		return (-1);
	return (0);
}

int		append_arg(char **orig, va_list args)
{
	char	*ret;

	if ((get_arg(&ret, args)) == -1)
		return (-1);
	!hash_check(g_conv_table, 'f') ? do_mods(&ret) : 0;
	*orig ? (*orig = ft_strjoin(orig, ret)) :
	(*orig = ret);
	(*ret) ? ft_memdel((void**)&ret) : 0;
	return (0);
}
