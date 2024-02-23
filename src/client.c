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

void	handle_signal2(int signbr)
{
	if (signbr == SIGUSR1)
		write(1, "Messaggio ricevuto.", 19);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*client_pid;

	signal(SIGUSR1, handle_signal2);
	signal(SIGUSR2, handle_signal2);

	if (ac != 3 || !(ft_strncmp(av[1], "-1", 2)))
	{
		write(1, "Insert a valid PID and the string to send.", 42);
		return (0);
	}
	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		client_pid = ft_itoa(getpid());
		if (!client_pid)
			return (0);
		handle_client(server_pid, client_pid);
		usleep(1000);
		handle_client(server_pid, av[2]);
		usleep(100);
		//free(client_pid);
	}
}
