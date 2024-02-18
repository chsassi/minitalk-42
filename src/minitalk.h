#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>

void	handle_signal(pid_t server_pid, int *array);
void	handle_client(pid_t server_pid, char *s);
int		handle_server(int signbr);

# endif