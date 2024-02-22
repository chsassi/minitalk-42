/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:44:44 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/20 14:38:22 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "minitalk.h"

t_octet ptr = (t_octet){0};

void	handle_server(int signbr)
{
	if (signbr == SIGUSR1)
		ptr.octet[ptr.index] = '0';
	else if (signbr == SIGUSR2)
		ptr.octet[ptr.index] = '1';
	ptr.index--;
}

int	main(void)
{
	char	c;

	ptr.index = 7;
	ptr.octet = (char *)ft_calloc(9, sizeof(char));
	if (!ptr.octet)
		return (1);
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_server);
	signal(SIGUSR2, handle_server);
	while (1)
	{
		pause();
		if (ptr.index == -1)
		{
			c = ft_atoi_base(ptr.octet, "01");
			write(1, &c, 1);
			if (c == 0)
				write (1, "\n", 1);
			ptr.index = 7;
			ft_bzero(ptr.octet, 8);
		}
	}
}

