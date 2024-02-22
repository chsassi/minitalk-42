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
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <strings.h>

typedef struct s_octet
{
	char	octet[8];
	char	*client_pid;
	int		index;
	int		flag;
}	t_octet;

void	handle_signal(pid_t server_pid, char letter);
void	handle_client(pid_t server_pid, char *s);
void	handle_server(int signbr);

# endif
