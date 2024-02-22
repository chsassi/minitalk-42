/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:38:17 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/20 14:38:22 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(pid_t server_pid, char letter)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (!((letter >> i) & 1))
			kill(server_pid, SIGUSR1);
		else 
			kill(server_pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

void	handle_client(pid_t server_pid, char *s)
{
	int		i;
	int		len;

	len = xstrlen(s);
	i = 0;
	while (s && i <= len)
		handle_signal(server_pid, s[i++]);
}
