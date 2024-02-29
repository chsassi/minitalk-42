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

/**
 * @brief Generates a unique process ID for the client.
 */
void	generate_client_pid(void);

/**
 * @brief Generates a ACK message to be sent to the client.
 * @return 0 with success.
 */
int		generate_message(void);

/**
 * @brief Fills an octet with the provided signal number.
 * @param signbr The signal number to fill the octet with.
 */
void	fill_octet(int signbr);

/* Client */

/**
 * @brief Sends a string to the server using kill().
 * @param server_pid The process ID of the server.
 * @param s The string to be sent, char by char, to fill the octet.
 */
void send_string(pid_t server_pid, char *s);

/**
 * @brief Receives a signal from the server.
 * @param signbr The signal number to be received.
 */
void receive_from_server(int signbr);

#endif