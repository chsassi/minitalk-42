# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <strings.h>

char	*strjoin_mntlk(char *str, char c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = strlen(str);
	res = (char *)calloc(len + 2, sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}

int	main()
{
	char str[4] = "ciao";
	char c = 'a';
	printf("%s\n", strjoin_mntlk(str, c));
}
