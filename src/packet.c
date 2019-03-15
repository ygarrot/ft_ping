/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 20:15:52 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int		set_packet(t_packet *pckt, t_ping *ping)
{
	static int msg_count = 0;
	int	i;

	pckt->hdr.type = ICMP_ECHO;
	pckt->hdr.un.echo.id = getpid();
	ft_bzero(pckt->msg, ping->pstat.size);
	for (i = 0; i < ping->pstat.size - 1; i++ ) 
		pckt->msg[i] = i + '0';
	pckt->msg[i] = 0;
	pckt->hdr.un.echo.sequence = msg_count++;
	pckt->hdr.checksum  = checksum(pckt, sizeof(t_packet));
	/* pckt->hdr.checksum = checksum(&pckt->hdr, sizeof(t_icmphdr)); */ 
	/* pckt->hdr.checksum += checksum(pckt->msg, */ 
/* ping->pstat.size); */ 
	ft_printf("%d\n", checksum);
	return (1);
}
