/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:11:27 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 18:12:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

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

#define RECV_TIMEOUT 333

int	ping_loop(t_ping *ping)
{
	int ttl_val=64;
	struct timeval tv_out; 
    tv_out.tv_sec = RECV_TIMEOUT; 
    tv_out.tv_usec = 0; 
  

	if (setsockopt(ping->socket, SOL_IP, IP_TTL,  
               &ttl_val, sizeof(ttl_val)) != 0) 
    { 
        ft_printf("\nSetting socket options  TTL failed!\n"); 
        return 1; 
    } 
    setsockopt(ping->socket, SOL_SOCKET, SO_RCVTIMEO, 
                   (const char*)&tv_out, sizeof tv_out); 
	ping->active = 1;
	gettimeofday(&ping->start_time, 0);
	ft_printf("Sending ping\n");
	while (ping->active)
	{
		set_packet(&ping->packet);
		ping_send(&ping->packet, ping->socket, &ping->sockaddr);
		ping_receive(ping->socket, &ping->sockaddr);
	}
	gettimeofday(&ping->end_time, 0);
	ft_printf("%ld\n", ping->start_time.tv_sec);
	return (1);
}


int	main(int ac, char **av)
{
	//	int		socket;
	t_ping	ping;

	if (usage(ac, av))
		return 1;
	ping.host_name = av[1];
	ping.socket = check_addr(&ping);
	ping_loop(&ping);
}
