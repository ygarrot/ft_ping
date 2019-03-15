/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:56:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 14:00:44 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	print_ping(t_ping *ping)
{
/* 		if(!(pckt.hdr.type ==69 && pckt.hdr.code==0)) */  
/* 		{ */ 
/* 			printf("Error..Packet received with ICMP  \ */
/* 					type %d code %d\n", */  
/* 					pckt.hdr.type, pckt.hdr.code); */ 
/* 		} */ 
		/* else */
		/* { */ 
			printf("%d bytes from %s (%s): icmp_seq=%d ttl=%d time=%Lf ms.\n",  \
					PACKETSIZE, "(NULL)", ping->host_addr, \
					ping->pstat.count, 
					ping->tstat.ttl, ping->tstat.intervale); 
		/* } */ 
	ping->pstat.count++;
	return (1);
}

int	print_stat(t_ping *ping)
{
	long double total_msec = timeval_to_double(ping->tstat.start, ping->tstat.current);
	printf("\n===%s ping statistics===\n", ping->host_name); 
	printf("\n%d packets transmitted, %d packets received, %f percent \
			packet loss. Total time: %Lf ms.\n\n",  
			ping->pstat.send, ping->pstat.rcv, 
			((ping->pstat.send - ping->pstat.rcv) / ping->pstat.count) * 100.0, 
			total_msec);  
	printf("rtt min/avg/max/mdev = %Lf/%Lf/%Lf/%Lf ms \n", ping->tstat.min, ping->tstat.avg, ping->tstat.max, ping->tstat.mdev);
	return (1);
}
