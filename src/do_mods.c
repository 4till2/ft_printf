/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:30:04 by yserkez           #+#    #+#             */
/*   Updated: 2018/12/27 16:33:00 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	shift_sign(char **ret, char **add)
{
	if (*ret[0] == '-' || *ret[0] == '+')
	{
		*add[0] = *ret[0];
		*ret[0] = '0';
	}
	else if (ft_strnstr(*ret, "0x", 2) || ft_strnstr(*ret, "0X", 2))
	{
		ft_strncpyn(add, *ret, 2);
		*ret = ft_memset(*ret, '0', 2);
	}
}

void	mod_width(char **ret)
{
	char	*add;
	int		len;
	char	fill;

	add = NULL;
	if ((len = g_width - ft_strlen(*ret)) < 1)
		return ;
	if (hash_check(g_flag_table, '0') && !hash_check(g_flag_table, '-') &&
		g_precision == -1)
		fill = '0';
	else
		fill = ' ';
	add = ft_chartostr(fill, len);
	if (fill == '0')
		shift_sign(ret, &add);
	if (hash_check(g_flag_table, '-'))
		*ret = ft_strjoin(ret, add);
	else
		*ret = ft_strjoinr(add, ret);
	add != NULL ? ft_memdel((void**)&add) : 0;
}

void	mod_prec(char **ret)
{
	char	*tmp;

	tmp = NULL;
	if (g_precision == 0 && ft_strequ(*ret, "0"))
	{
		free(*ret);
		*ret = "";
	}
	else if (hash_check(g_conv_table, 'o') || hash_check(g_conv_table, 'd') ||
		hash_check(g_conv_table, 'i') || hash_check(g_conv_table, 'u'))
	{
		if (**ret == '-')
		{
			g_precision++;
			tmp = ft_chartostr('0', g_precision - ft_strlen(*ret));
			shift_sign(ret, &tmp);
		}
		else
			tmp = ft_chartostr('0', g_precision - ft_strlen(*ret));
		*ret = ft_strjoinr(tmp, ret);
	}
	else if (hash_check(g_conv_table, 's'))
		(tmp = *ret) ?
		(*ret = ft_strsub(*ret, 0, g_precision)) : 0;
	tmp != NULL ? ft_memdel((void**)&tmp) : 0;
}

void	mod_hash(char **ret)
{
	if (hash_check(g_conv_table, 'o'))
		*ret = ft_strjoinr("0", ret);
	if ((hash_check(g_conv_table, 'x') && ft_strcmp(*ret, "0") != 0) ||
		hash_check(g_conv_table, 'p'))
		*ret = ft_strjoinr("0x", ret);
	if (hash_check(g_conv_table, 'X') && ft_strcmp(*ret, "0") != 0)
		*ret = ft_strjoinr("0X", ret);
}

void	do_mods(char **ret)
{
	if (g_precision != -1)
		mod_prec(ret);
	if (hash_check(g_conv_table, 'i') || hash_check(g_conv_table, 'd'))
	{
		if (*ret[0] != '-' && (hash_check(g_flag_table, '+') ||
			hash_check(g_flag_table, ' ')))
			hash_check(g_flag_table, '+') ? (*ret = ft_strjoinr("+", ret)) :
			(*ret = ft_strjoinr(" ", ret));
	}
	else if ((hash_check(g_conv_table, 'p') || ((hash_check(g_conv_table, 'x')
			|| hash_check(g_conv_table, 'X')) && g_precision != 0)
		|| hash_check(g_conv_table, 'o')) && hash_check(g_flag_table, '#'))
		mod_hash(ret);
	if (g_width > (int)ft_strlen(*ret))
		mod_width(ret);
}
