#include "libft.h"

int	*put_binary(int nbr)
{
	int	array[8];
	int	i;

	i = 0;
	if (nbr >= 2)
		put_binary(nbr / 2);
	while (i < 8)
	{
		array[i] = nbr % 2;
		i++;
	}
	return (array);
}
