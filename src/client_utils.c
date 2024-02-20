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
		array = binary_to_octet((int)s[i]);
		handle_signal(server_pid, array);
		i++;
	}
}
