/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yserkez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 12:50:55 by yserkez           #+#    #+#             */
/*   Updated: 2018/10/22 13:46:27 by yserkez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j] && n-- > 0)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
