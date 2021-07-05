/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuki <kyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:42:38 by kyuki             #+#    #+#             */
/*   Updated: 2021/07/05 12:42:39 by kyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "../libft/libft.h"
#define COMFIRM_SIG 0
#define PID_MIN 0
#define PID_MAX 99999

int	ft_atoi(const char *str)
{
	unsigned int	res;
	int				negative;

	res = 0;
	negative = 1;
	while (*str == '\t' || *str == '\v' || *str == '\n' \
		|| *str == '\r' || *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
		if (res > PID_MAX || negative == -1)
			return (-1);
	}
	return (res);
}

void	ft_sig_ack(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd("Correctly send message[ACK!]\n", STDERR_FILENO);
	if (sig == SIGUSR2)
		ft_putstr_fd("Error: send another pid\n", STDERR_FILENO);
	exit(1);
}

void	ft_send_char(pid_t pid, char c)
{
	int	j;
	int	bit;

	j = -1;
	while (++j < 8)
	{
		bit = (c >> j) & 1;
		if (bit == 1)
			bit = kill(pid, SIGUSR1);
		else
			bit = kill(pid, SIGUSR2);
		if (bit == -1)
		{
			ft_putstr_fd("Error: send signal to server", STDERR_FILENO);
			exit(1);
		}
		usleep(100);
	}
}

void	ft_client(char **argv)
{
	pid_t	pid;
	int		i;

	i = -1;
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Error: PID\n", STDERR_FILENO);
		return ;
	}
	if (kill(pid, COMFIRM_SIG) == -1)
	{
		ft_putstr_fd("Error: PID\n", STDERR_FILENO);
		return ;
	}
	while (argv[2][++i] != '\0')
		ft_send_char(pid, argv[2][i]);
	ft_send_char(pid, argv[2][i]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (signal(SIGUSR1, ft_sig_ack) == SIG_ERR)
			return (1);
		if (signal(SIGUSR2, ft_sig_ack) == SIG_ERR)
			return (1);
		ft_client(argv);
	}
	else
		ft_putstr_fd("Error: Argument\n", STDERR_FILENO);
}
