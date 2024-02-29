/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:44:44 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/20 14:38:22 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	g_ptr = (t_client){0};

void	receive_from_server(int signbr)
{
	if (signbr == SIGUSR1)
	{
	}
	if (signbr == SIGUSR2)
	{
		write(1, "Message Received.\n", 19);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	char				*client_pid;
	struct sigaction	sa;

	sa = (struct sigaction){0};
	sa.sa_handler = receive_from_server;
	sigaction(SIGUSR2, &sa, NULL);
	if (ac != 3)
	{
		write(1, "Insert a valid PID and the string to send.", 42);
		return (0);
	}
	g_ptr.server_pid = ft_atoi(av[1]);
	if (g_ptr.server_pid <= 0 || kill(g_ptr.server_pid, 0) != 0)
		return (1);
	client_pid = ft_itoa(getpid());
	if (!client_pid)
		return (free(client_pid), 1);
	g_ptr.flag = SEND_PID;
	send_string(g_ptr.server_pid, client_pid);
	free(client_pid);
	g_ptr.flag = SEND_MSG;
	send_string(g_ptr.server_pid, av[2]);
	pause();
}
