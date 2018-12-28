/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccodiga <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:24:28 by ccodiga           #+#    #+#             */
/*   Updated: 2018/12/27 17:23:34 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char **s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = NULL;
	if (!(str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1 != NULL && (*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	if ((*s1)[0])
		ft_memdel((void**)s1);
	return (str);
}
