#include "libft.h"

void        ft_strncpyn(char **dst, char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < len)
	{
		(*dst)[i] = src[i];
		i++;
	}
}
