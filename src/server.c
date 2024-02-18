/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:44:44 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/07 23:45:16 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int conversion(int array[7])
{

}

int	handler(int signbr)
{
	char	c;
	int		array[7];
	int		i;

	i = 0;
	while (i < 8)
	{
		if (signbr == SIGUSR1)
			array[i++] = 0;
		else if (signbr == SIGUSR1)
			array[i++] = 1;
	}
	ft_putnbr_base()
}

int	main(void)
{
	ft_printf("PID: %d", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	pause();
}