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

t_server	g_ptr = (t_server){0};

static void	convert_from_bits(void)
{
	int	res;
	int	i;

	res = 0;
	i = -1;
	while (++i < 8)
		res = res << 1 | g_ptr.octet[i];
	g_ptr.c = res;
}

void	generate_client_pid(void)
{
	if (g_ptr.c == 0)
	{
		g_ptr.flag = SEND_MSG;
		g_ptr.index = 7;
		return ;
	}
	g_ptr.client_pid = g_ptr.client_pid * 10 + (g_ptr.c - '0');
}

int	generate_message(void)
{
	write(1, &g_ptr.c, 1);
	if (g_ptr.c == 0)
	{
		ft_printf("\n");
		kill(g_ptr.client_pid, SIGUSR2);
		g_ptr.flag = SEND_PID;
		g_ptr.client_pid = 0;
	}
	return (EXIT_SUCCESS);
}

void	fill_octet(int signbr)
{
	if (signbr == SIGUSR1)
		g_ptr.octet[g_ptr.index] = 0;
	else if (signbr == SIGUSR2)
		g_ptr.octet[g_ptr.index] = 1;
	g_ptr.index--;
	if (g_ptr.index == -1)
	{
		convert_from_bits();
		if (g_ptr.flag == SEND_PID)
			generate_client_pid();
		else if (g_ptr.flag == SEND_MSG)
			generate_message();
		g_ptr.index = 7;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_handler = fill_octet;
	ft_printf("PID: %d\n", getpid());
	g_ptr.flag = SEND_PID;
	g_ptr.index = 7;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
	{
	}
}
