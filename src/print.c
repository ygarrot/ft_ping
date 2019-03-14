/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:56:47 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/13 16:13:10 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	ping_pring()
{
	if(flag) 
	{ 
		if(!(pckt.hdr.type ==69 && pckt.hdr.code==0))  
		{ 
			printf("Error..Packet received with ICMP  \
					type %d code %d\n",  
					pckt.hdr.type, pckt.hdr.code); 
		} 
		else
		{ 
			printf("%d bytes from %s (h: %s)  \
					(%s) msg_seq=%d ttl=%d  \
					rtt = %Lf ms.\n",  \
					PING_PKT_S, ping_dom, rev_host,  \
					ping_ip, msg_count, 
					ttl_val, rtt_msec); 

			msg_received_count++; 
		} 
	} 
}

int	print_stat()
{
	clock_gettime(CLOCK_MONOTONIC, &tfe); 
	double timeElapsed = ((double)(tfe.tv_nsec -  
				tfs.tv_nsec))/1000000.0; 
	total_msec = (tfe.tv_sec-tfs.tv_sec)*1000.0+  
		timeElapsed;
	printf("\n===%s ping statistics===\n", ping_ip); 
	printf("\n%d packets sent, %d packets received, %f percent \
			packet loss. Total time: %Lf ms.\n\n",  
			msg_count, msg_received_count, 
			((msg_count - msg_received_count)/msg_count) * 100.0, 
			total_msec);  
}
