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

char	*g_array = NULL;

void	handle_server(int signbr)
{
	if (signbr == SIGUSR1)
		(*g_array++) = 0;
	else if (signbr == SIGUSR2)
		(*g_array++) = 1;
}

int	main(void)
{
	ft_printf("PID: %d", getpid());
	pause();
	signal(SIGUSR1, handle_server);
	signal(SIGUSR2, handle_server);
}
