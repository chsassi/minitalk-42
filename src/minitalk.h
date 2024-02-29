/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:32:27 by chsassi           #+#    #+#             */
/*   Updated: 2024/02/19 15:32:28 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <bits/sigaction.h>

typedef enum s_action
{
	SEND_PID,
	SEND_MSG
}	t_action;

typedef struct s_server
{
	char	c;
	int		octet[8];
	int		index;
	int		client_pid;
	int		flag;
}	t_server;

typedef struct s_client
{
	int		server_pid;
	int		flag;
}	t_client;

/* Server */
void	fill_octet(int signbr);

/* Client */
void	send_string(pid_t server_pid, char *s);
void	receive_from_server(int signbr);

#endif
