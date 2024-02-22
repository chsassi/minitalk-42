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

t_octet g_ptr = (t_octet){0};

void	handle_server(int signbr)
{
	if (signbr == SIGUSR1)
		g_ptr.octet[g_ptr.index--] = '0';
	else if (signbr == SIGUSR2)
		g_ptr.octet[g_ptr.index--] = '1';
}

int	main(void)
{
	char	c;
	int		j;

	j = 0;
	g_ptr.index = 7;
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handle_server);
	signal(SIGUSR2, handle_server);
	while (1)
	{
		pause();
		
		if (g_ptr.index == -1)
		{
			c = ft_atoi_base(g_ptr.octet, "01");
			ft_printf("%c\n", c);
			if (g_ptr.flag == 0)
			{
				if (c == 0)
				{
					g_ptr.flag = 1;
					continue ;
				}
				g_ptr.client_pid = strjoin_mntlk(g_ptr.client_pid, c);
				ft_printf("qui\n");
				ft_printf("%s\n", g_ptr.client_pid);
				if (!g_ptr.client_pid)
					return (1);
				j++;
			}
			else if (g_ptr.flag == 1)
			{
				write(1, &c, 1);
				if (c == 0)
				{
					write (1, "\n", 1);
					kill(ft_atoi(g_ptr.client_pid), SIGUSR2);
					free(g_ptr.client_pid);
					g_ptr.flag = 0;
				}
			}
			g_ptr.index = 7;
/* 			ft_bzero(g_ptr.octet, 8);
 */		}
	}
}

