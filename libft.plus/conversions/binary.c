/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:31:58 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/20 13:05:03 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*binary_to_octet(int nb)
{
	int		i;
	int		j;
	char	*res;

	i = 7;
	j = 0;
	res = (char *)calloc(8, sizeof(char));
	if (!res)
		return (NULL);
	res[8] = '\0';
	while (j < 8)
	{
		if (nb == 1)
			res[i--] = 1;
		else if (nb % 2)
			res[i--] = 1;
		else if ((nb % 2) == 0)
			res[i--] = 0;
		nb /= 2;
		j++;
	}
	return (res);
}

/* int main()
{
	int n = 50;
	int i = 0;
	char *x = binary_to_octet(n);
	while(i < 8)
	{
		printf("%i", x[i]);
		i++;
	}
} */
