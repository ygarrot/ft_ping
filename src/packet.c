/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:45:55 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 17:38:07 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int		set_packet(t_packet *pckt)
{
	static int msg_count = 0;
	size_t	i;

	ft_bzero(pckt, sizeof(t_packet));
	ft_bzero(&pckt->hdr, sizeof(t_icmphdr));
	pckt->hdr.type = ICMP_ECHO;
	pckt->hdr.un.echo.id = getpid();
	for (i = 0; i < sizeof(pckt->msg) - 1; i++ ) 
		pckt->msg[i] = i + '0';
	pckt->msg[i] = 0;
	pckt->hdr.un.echo.sequence = msg_count++;
	pckt->hdr.checksum = checksum(pckt, sizeof(*pckt)); 
	return (1);
}
