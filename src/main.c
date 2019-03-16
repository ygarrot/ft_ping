/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:11:27 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/16 15:35:43 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

t_ping *g_ping;

void	stop_loop(int signal)
{
	(void)signal;
	print_stat(g_ping);
	exit(1);
}

int	usage(int ac, char **av)
{
	(void)av;
	if (ac < 2)
	{
		ft_printf("Please give me an address and (maybe) a port\n");
		return 1;
	}
	return 0;
}


int	ping_loop(t_ping *ping)
{
	struct timeval tv_out; 
	tv_out.tv_sec = ping->tstat.timeout; 
	tv_out.tv_usec = 0; 


	if (setsockopt(ping->socket, SOL_IP, IP_TTL,
				&ping->tstat.ttl, sizeof(int)) != 0)
	{ 
		ft_printf("\nSetting socket options  TTL failed!\n");
		return 1; 
	} 
	setsockopt(ping->socket, SOL_SOCKET, SO_RCVTIMEO,
			(const char*)&tv_out, sizeof tv_out);
	gettimeofday(&ping->tstat.start, 0);
	while (1)
	{
		set_packet(&ping->packet, ping);
		ping_send(&ping->packet, ping->socket, ping);
		intervale();
		ping_receive(ping->socket, ping);
		ping->tstat.intervale = intervale();
		wait_for(ping->tstat.delay);
		if (!(ping->opt & QUIET))
			print_ping(ping);
		ping->pstat.count++;
		set_time_stat(ping);
	}
	return (1);
}


int	main(int ac, char **av)
{
	t_ping	ping;

	g_ping = &ping;
	ft_bzero(&ping, sizeof(t_ping));
	if (usage(ac, av))
		return 1;
	ping.opt = ft_getoptvalue(ac, av, OPT_STR, ping.opt_tab);
	ping_ctor(&ping);
	ping.host_name = av[1];
	if ((ping.socket = check_addr(&ping)) == ERROR_CODE)
		return EXIT_FAILURE;
	signal(SIGINT, stop_loop);
	print_summary(&ping);
	ping_loop(&ping);
}
