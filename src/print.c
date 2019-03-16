/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:56:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/16 12:42:49 by ygarrot          ###   ########.fr       */
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
			printf ("%d bytes from ", ping->pstat.size);
			if (ping->opt & NUMERIC)
				printf("%s:", ping->host_addr);
			else
				printf("%s (%s):","NULL", ping->host_addr);
			printf(" icmp_seq=%d ttl=%d time=%.2Lf ms.\n",  \
					ping->pstat.count, 
					ping->tstat.ttl, ping->tstat.intervale); 
		/* } */ 
	return (1);
}

int	print_stat(t_ping *ping)
{
	/* long double total_msec = timeval_to_double(ping->tstat.start, ping->tstat.current); */
	printf("--- %s ping statistics ---\n", ping->host_name);
	printf("%d packets transmitted, %d received, %d%% packet loss, time %.0Lf ms\n",
			ping->pstat.send, ping->pstat.rcv,
			(int)(((double)(ping->pstat.send - ping->pstat.rcv) / ping->pstat.count) * 100), 
			ping->tstat.all);  
	printf("rtt min/avg/max/mdev = %Lf/%Lf/%Lf/%Lf ms\n", ping->tstat.min, ping->tstat.avg, ping->tstat.max, ping->tstat.mdev);
	return (1);
}
