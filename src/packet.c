/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 19:30:11 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int		set_packet(t_packet *pckt, t_ping *ping)
{
	static int msg_count = 0;
	int	i;

	pckt->hdr.type = ICMP_ECHO;
	pckt->hdr.un.echo.id = getpid();
	for (i = 0; i < ping->pstat.size ; i++ ) 
		pckt->msg[i] = i + '0';
	pckt->msg[i] = 0;
	pckt->hdr.un.echo.sequence = msg_count++;
	pckt->hdr.checksum = checksum(pckt, ping->pstat.size + sizeof(t_icmphdr)); 
	return (1);
}
