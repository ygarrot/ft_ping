/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:21:09 by ygarrot           #+#    #+#             */
/*   Updated: 2019/03/14 13:49:25 by ygarrot          ###   ########.fr       */
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
	setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &reuseaddr, sizeof(reuseaddr));
	ping->sockaddr = is_ipv4 ?
		(t_sockaddr*)get_ipv4_addr(NULL, ping->port, &sin, ping->host_entity->h_addrtype)
		: (t_sockaddr*)get_ipv6_addr(NULL, ping->port, &sin2);
	return (sock);
}

/*
**struct hostent {
**               char  *h_name;             official name of host
**                char **h_aliases;          alias list
**               int    h_addrtype;         host address type 
**               int    h_length;           length of address 
**               char **h_addr_list;        list of addresses 
**           }
**           #define h_addr h_addr_list[0]  for backward compatibility
*/

#define PORT_TMP 12

int	check_addr(t_ping *ping)
{
	int		is_ipv4;
	/* char *ip=(char*)malloc(NI_MAXHOST*sizeof(char)); */

	if ((ping->host_entity = gethostbyname(ping->host_name)) == NULL) 
		return (0); 
	is_ipv4 = ip_version(ping->host_entity->h_addr) == 4;
	return (create_socket(ping, is_ipv4));
}
