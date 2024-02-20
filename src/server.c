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

#include "minitalk.h"



int	main(void)
{
	// char	*res;
	// char	c;
	// int		i;

	// i = 0;
	// res = NULL;
	ft_printf("PID: %d", getpid());
	// while (1)
	// {
	pause();
	signal(SIGUSR1, handle_server);
	signal(SIGUSR2, handle_server);
	// 	if (*g_array == '\0')
	// 	{
	// 		c = btoc(&g_array[0]);
	// 		if (res && c == '\0')
	// 		{
	// 			ft_printf("%s", res);
	// 			free(res);
	// 			continue ;
	// 		}
	// 		res = ft_strjoin(c, res);
	// 		ft_bzero(&g_array[0], 8);
	// 		g_array = &g_array[0];
	// 	}
	// }
}
