/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:11:27 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 14:10:14 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	ping_loop(t_ping *ping)
{
	ping->active = 1;
	gettimeofday(&ping->start_time, 0);
	while (ping->active)
	{
		ping_receive(ping->socket);
	}
	gettimeofday(&ping->end_time, 0);
	printf("%ld\n", ping->start_time.tv_sec);
	return (1);
}


int	main(int ac, char **av)
{
//	int		socket;
	t_ping	ping;

	(void)ac;
	(void)av;
	ping.socket = check_addr(&ping);
	ping_loop(&ping);
}
