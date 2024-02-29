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

static void	send_char(pid_t server_pid, char letter)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = (letter >> i) & 1;
		if (!bit)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

void	send_string(pid_t server_pid, char *s)
{
	int		i;
	int		len;

	len = xstrlen(s);
	i = 0;
	while (s && i <= len)
		send_char(server_pid, s[i++]);
}
