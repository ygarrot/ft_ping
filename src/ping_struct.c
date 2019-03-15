/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:10:14 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 19:39:25 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

void	ping_ctor(t_ping *ping)
{
	ft_bzero(ping, sizeof(t_ping));
	ft_bzero(&ping->pstat, sizeof(t_packet_stat));
	ft_bzero(&ping->tstat, sizeof(t_time_stat));
	ping->pstat.size = PACKET_SIZE_DEFAULT;
	ping->tstat.ttl = TTL_DEFAULT;
	ping->tstat.timeout = DEFAULT_TIMEOUT;
	ping->tstat.delay = 1.0;
	func_tab(ping);
	ping->pstat.size -= sizeof(t_icmphdr);
	ping->packet.msg = ft_memalloc(ping->pstat.size);
}


void	ping_dtor(t_ping *ping)
{
	ft_memdel((void**)&ping->packet.msg);
}
