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

extern char array[8];

void	handle_signal(pid_t server_pid, char *array);
void	handle_client(pid_t server_pid, char *s);
void	handle_server(int signbr);

# endif
