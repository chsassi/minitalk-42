/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:55:27 by chsassi           #+#    #+#             */
/*   Updated: 2023/11/21 15:58:58 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *length)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		ft_putchar(str[i], length);
		i++;
	}
}

/* int		main(void)
{
	char	*str = "Hello World!\n";
	int		length = 0;
	ft_putstr(str, &length);
	printf("%i\n", length);
} */
