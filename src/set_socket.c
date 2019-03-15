/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:21:09 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/15 21:20:21 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

int	create_socket(t_ping *ping, int is_ipv4)
{
	int				sock;
	int				reuseaddr;
	t_sockaddr_in6	sin2;
	t_sockaddr_in	sin;

	ft_bzero(&sin2, sizeof(sin2));
	ft_bzero(&sin, sizeof(sin));
	sock = set_socket(is_ipv4);
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO 
| ((ping->opt & DEBUG)  * SO_DEBUG) , &reuseaddr, sizeof(reuseaddr));
	/* ping->sockaddr = */ 
	/* get_ipv4_addr(ping->host_entity->h_name, ping->port, &ping->sockaddr, ping->host_entity->h_addrtype); */
	/* ping->sockaddr = is_ipv4 ? */
		/* (t_sockaddr*)get_ipv4_addr(NULL, ping->port, &sin, ping->host_entity->h_addrtype) */
		/* : (t_sockaddr*)get_ipv6_addr(NULL, ping->port, &sin2); */
	/* ping->sockaddr.sin_addr.s_addr = *(long*)ping->host_entity->h_addr; */
	ping->sockaddr = ping->host_entity->ai_addr;
	ping->sockaddr_len = ping->host_entity->ai_addrlen;
	return (sock);
}

/*
**	struct addrinfo {
**        int              ai_flags;
**        int              ai_family;
**        int              ai_socktype;
**        int              ai_protocol;
**        socklen_t        ai_addrlen;
**        struct sockaddr *ai_addr;
**        char            *ai_canonname;
**        struct addrinfo *ai_next;
**     };
*/

#define PORT_TMP 12

int	check_addr(t_ping *ping)
{
	t_addrinfo tmp;
	void	*ptr;
	int		is_ipv4;

	ft_bzero(&tmp, sizeof(tmp));
	tmp.ai_family = PF_UNSPEC;
	tmp.ai_socktype = SOCK_RAW;
	tmp.ai_flags |= AI_CANONNAME;
	if (getaddrinfo(ping->host_name, NULL, &tmp, &ping->host_entity)
!= 0)
		return (0);
	ptr = &((t_sockaddr_in*)ping->host_entity->ai_addr)->sin_addr;
	is_ipv4 = ping->host_entity->ai_family == PF_INET;
	inet_ntop(ping->host_entity->ai_family, ptr,
  ping->host_addr, 100);
	return (create_socket(ping, is_ipv4));
}
