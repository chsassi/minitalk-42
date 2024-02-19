/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 23:44:44 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/07 23:45:15 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(pid_t server_pid, char *array)
{
	int	i;

	i = 0;
	while (array && i < 8)
	{
		if (array[i] == 0)
			kill(SIGUSR1, server_pid);
		else if (array[i] == 1)
			kill(SIGUSR2, server_pid);
		i++;
	}
}

void	handle_client(pid_t server_pid, char *s)
{
	int		i;
	char	*array;

	i = 0;
	while (s && s[i])
	{
		array = put_binary((int)s[i]);
		handle_signal(server_pid, array);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	server_pid = ft_atoi(av[1]);
	if (ac != 3 || )
		write(1, "", );
	else
		handle_client(server_pid, av[2]);
}
