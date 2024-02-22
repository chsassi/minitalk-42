#include "libft.h"

char	*strjoin_mntlk(char *str, int c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (!str)
	{
		res = (char *)ft_calloc(2, sizeof(char));
		res[i] = c;
		res[i + 1] = '\0';
		return (res);
	}
	len = xstrlen(str);
	res = (char *)ft_calloc(len + 2, sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	free(str);
	return (res);
}

